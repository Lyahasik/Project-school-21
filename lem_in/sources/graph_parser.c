/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:26:00 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/05 20:38:00 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Обработка шагов.
** @param graphic указатель для работы с данными графики.
** @param ants муравьи делающие шаг.
** @param step номер шага.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	recording_steps(t_graphic *graphic, char **ants, int step)
{
	char	**temp;
	int		ant_num;
	int		room;
	int		i;

	i = -1;
	while (ants[++i])
	{
		if ((temp = ft_strsplit(ants[i], '-')) == NULL)
			return (ft_out_message(ERR_MEM, 0));
		ant_num = ft_atoi(temp[0] + 1);
		if ((room = find_room(graphic->data, temp)) == -1)
			return (ft_mem_free_two((void**)temp));
		if (!(graphic->steps[step][i].name = ft_strdup(temp[0])))
			return (ft_out_message(ERR_MEM, 0) + ft_mem_free_two((void**)temp));
		graphic->steps[step][i].room_destination = room;
		ft_mem_free_two((void**)temp);
	}
	return (1);
}

/*
** Проход по строкам с шагами по путям муравьев.
** @param graphic указатель для работы с данными графики.
** @param lines строки со входа.
** @param i указатель с номером строки.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	processing_steps(t_graphic *graphic, char **lines, int i)
{
	char	**ants;
	int		step;

	if (lines == NULL)
		return (0);
	graphic->steps_amount = ft_lines_count(lines + i + 1);
	if (!create_steps(graphic))
		return (ft_out_message(ERR_MEM, 0));
	step = -1;
	while (lines[++i])
	{
		if ((ants = ft_strsplit(lines[i], ' ')) == NULL)
			return (ft_out_message(ERR_MEM, 0));
		graphic->step_ants_amount[++step] = ft_lines_count(ants);
		if (!(graphic->steps[step] = (t_ant*)malloc(sizeof(t_ant) *
			graphic->step_ants_amount[step])))
			return (ft_out_message(ERR_MEM, 0) + ft_mem_free_two((void**)ants));
		if (!(recording_steps(graphic, ants, step)))
			return (ft_mem_free_two((void**)ants));
		ft_mem_free_two((void**)ants);
	}
	return (1);
}

/*
** Проход по строкам.
** @param graphic указатель для работы с данными графики.
** @param lines строки со входа.
** @param i указатель с номером строки.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	recording_lines(t_graphic *graphic, char **lines, int *i)
{
	while (lines[++(*i)])
	{
		if (graphic->data->rooms == NULL)
		{
			create_rooms(graphic->data, graphic->data->rooms_amount, lines[*i]);
			if (!processing_rooms(graphic->data, lines[*i])
				|| !find_ants(graphic->data, lines[*i]))
				return (ft_mem_free_two((void**)lines));
		}
		else
		{
			if (lines[*i][0] == 'L' && lines[*i][1] == '1')
				break ;
			if (!processing_connections(graphic->data, lines[*i]))
				return (ft_mem_free_two((void**)lines));
		}
	}
	return (1);
}

/*
** Проверка всех данных на корректность.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	recording_graphic(t_graphic *graphic)
{
	int		i;
	char	**lines;

	if (!(lines = ft_strsplit(graphic->data->input, '\n')))
		return (ft_out_message(ERR_MEM, 0));
	if (!check_line_empty(graphic->data, lines))
		return (ft_mem_free_two((void**)lines));
	i = -1;
	if (!recording_lines(graphic, lines, &i))
		return (0);
	if (!create_connections(graphic->data, graphic->data->rooms_amount)
		|| !filling_data(graphic->data, lines))
		return (ft_mem_free_two((void**)lines));
	return (processing_steps(graphic, lines, i - 1) +
			ft_mem_free_two((void**)lines));
}

/*
** Считывание результата основного алгоритма.
** @param graphic указатель для работы с данными.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			reading_result(t_graphic *graphic)
{
	if (input_read(graphic->data) == 0 || recording_graphic(graphic) == 0
		|| !create_ants(graphic))
	{
		return (0);
	}
	return (1);
}
