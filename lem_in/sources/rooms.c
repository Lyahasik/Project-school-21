/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:41:09 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:48:16 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Проверка на дубликаты имен/координат комнат.
** @param data указатель для работы с данными алгоритма.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			check_rooms_duplicate(t_data *data)
{
	char	*name;
	int		x;
	int		y;
	int		i;
	int		j;

	i = -1;
	while (++i < data->rooms_amount)
	{
		j = i;
		name = data->rooms[i].name;
		x = data->rooms[i].x;
		y = data->rooms[i].y;
		while (++j < data->rooms_amount)
		{
			if (!ft_strcmp(name, data->rooms[j].name))
				return (ft_out_message(ERR_ROOM_DNAME, 0));
			if (x == data->rooms[j].x && y == data->rooms[j].y)
			{
				return (ft_out_message(ERR_ROOM_DCOOR, 0));
			}
		}
	}
	return (1);
}

/*
** проверка начала строки.
** @param line проверяемая строка.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	check_line_begin(char *line)
{
	if (line[0] == '#')
	{
		if (line[1] == '#')
		{
			return (check_line_point(line));
		}
		return (-1);
	}
	if (line[0] == 'L')
	{
		return (ft_out_message(ERR_ROOM_NAME, 0));
	}
	return (1);
}

/*
** Проверка корректности ввода строки содержащей комнату.
** @param data указатель для работы с данными алгоритма.
** @param line проверяемая строка.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			processing_rooms(t_data *data, char *line)
{
	char	**temp;
	int		begin;

	if (data->rooms == NULL && data->ants_num > 0)
	{
		if ((begin = check_line_begin(line)) != 1)
			return (begin);
		if (ft_str_char_count(line, ' ') != 2 || ft_sepchar(line, ' ') != 2)
			return (ft_out_message(ERR_ROOM_SPACE, 0));
		if (!(temp = ft_strsplit(line, ' ')))
			return (ft_out_message(ERR_MEM, 0));
		if (ft_lines_count(temp) != 3)
		{
			ft_mem_free_two((void**)temp);
			return (ft_out_message(ERR_ROOMS_INV, 0));
		}
		if (!ft_check_atoi_int(temp[1]) || !ft_check_atoi_int(temp[2]))
		{
			return (ft_out_message(ERR_COORD, ft_mem_free_two((void**)temp)));
		}
		ft_mem_free_two((void**)temp);
		data->rooms_amount++;
	}
	return (1);
}

/*
** Запись данных комнат из строки.
** @param data указатель для работы с данными алгоритма.
** @param line проверяемая строка.
** @param point указатель на значение обозначения комнат.
** @param count номер комнаты.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	recording_room(t_data *data, char *line, int *point, int count)
{
	char	**temp;

	if (!(temp = ft_strsplit(line, ' ')))
		return (ft_out_message(ERR_MEM, 0));
	if (!(data->rooms[count].name = ft_strdup(temp[0])))
		return (ft_out_message(ERR_MEM, 0) + ft_mem_free_two((void**)temp));
	data->rooms[count].x = ft_atoi(temp[1]);
	data->rooms[count].y = ft_atoi(temp[2]);
	if (*point == 2)
	{
		*point = 0;
		data->start = count;
	}
	if (*point == 3)
	{
		*point = 0;
		data->end = count;
	}
	ft_mem_free_two((void**)temp);
	return (1);
}

/*
** Предпроверка на повторяющиеся обозначения комнат.
** @param data указатель для работы с данными алгоритма.
** @param line проверяемая строка.
** @param point указатель на значение обозначения комнат.
** @param count номер комнаты.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			filling_rooms(t_data *data, char *line, int *point, int *count)
{
	int	temp;

	if (line[0] == '#' && line[1] == '#')
	{
		temp = check_line_point(line);
		if (*point == temp && temp == 2)
			return (ft_out_message(ERR_START_NUM, 0));
		if (*point == temp && temp == 2)
			return (ft_out_message(ERR_END_NUM, 0));
		*point = temp;
		if (*point == 2 && data->start != -1)
			return (ft_out_message(ERR_START_NUM, 0));
		if (*point == 3 && data->end != -1)
			return (ft_out_message(ERR_END_NUM, 0));
		return (1);
	}
	recording_room(data, line, point, *count);
	(*count)++;
	return (1);
}
