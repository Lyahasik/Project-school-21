/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:15:06 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:42:25 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Проверка на отстутствие обозначений комнат.
** @param data указатель для работы с данными алгоритма.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	check_points(t_data *data)
{
	if (data->start == -1)
		return (ft_out_message(ERR_START_MISS, 0));
	if (data->end == -1)
		return (ft_out_message(ERR_END_MISS, 0));
	return (1);
}

/*
** Построчная запись входных данных в структуру.
** @param data указатель для работы с данными алгоритма.
** @param lines строки со входа.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			filling_data(t_data *data, char **lines)
{
	int	i;
	int	count;
	int	point;
	int	error;

	count = 0;
	point = 0;
	i = skip_ants(lines);
	while (lines[++i])
	{
		if (lines[i][0] == 'L' && lines[i][1] == '1')
			break ;
		if (lines[i][0] == '#' && lines[i][1] != '#')
			continue ;
		if (lines[i][0] == '#' || ft_str_char_count(lines[i], ' ') == 2)
			error = filling_rooms(data, lines[i], &point, &count);
		else
			error = filling_connections(data, lines[i]);
		if (error == 0)
			return (0);
	}
	if (!check_rooms_duplicate(data) || !check_points(data))
		return (0);
	return (1);
}

/*
** Проверка всех строк на корректность ввода.
** @param data указатель для работы с данными алгоритма.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			recording_data(t_data *data)
{
	int		i;
	char	**lines;

	if (!(lines = ft_strsplit(data->input, '\n')))
		return (ft_out_message(ERR_MEM, 0));
	if (!check_line_empty(data, lines))
		return (ft_mem_free_two((void**)lines));
	i = -1;
	while (lines[++i])
	{
		if (data->rooms == NULL)
		{
			create_rooms(data, data->rooms_amount, lines[i]);
			if (!processing_rooms(data, lines[i]) || !find_ants(data, lines[i]))
				return (ft_mem_free_two((void**)lines));
		}
		else
		{
			if (!processing_connections(data, lines[i]))
				return (ft_mem_free_two((void**)lines));
		}
	}
	if (!create_connections(data, data->rooms_amount))
		return (ft_mem_free_two((void**)lines));
	return (filling_data(data, lines) + ft_mem_free_two((void**)lines));
}
