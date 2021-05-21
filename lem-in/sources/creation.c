/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:13:49 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:36:03 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Выделение памяти для матрицы связей.
** @param data указатель для работы с данными алгоритма.
** @param amount количество комнат.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int		create_connections(t_data *data, int amount)
{
	int	i;

	if (amount == 0 || data->rooms == NULL)
		return (ft_out_message(ERR_ROOMS_NO, 0));
	if (data->connections == NULL && amount > 0)
	{
		if (!(data->connections = (int**)malloc(sizeof(int*) * amount)))
		{
			return (ft_out_message(ERR_MEM, 0));
		}
		i = -1;
		while (++i < amount)
		{
			if (!(data->connections[i] = (int*)malloc(sizeof(int) * amount)))
			{
				return (ft_out_message(ERR_MEM, 0));
			}
			ft_numset(data->connections[i], 0, amount);
		}
	}
	return (1);
}

/*
** Выделение памяти для массива комнат.
** @param data указатель для работы с данными алгоритма.
** @param amount количество комнат.
** @param line проверяемая строка.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int		create_rooms(t_data *data, int amount, char *line)
{
	int	i;

	if (amount > 0 && line[0] != '#' && ft_str_char_count(line, ' ') != 2
		&& ft_str_char_count(line, '-') == 1)
	{
		if (data->rooms_amount == 0)
		{
			return (ft_out_message(ERR_ROOMS_NO, 0));
		}
		if (!(data->rooms = (t_room*)malloc(sizeof(t_room) * amount)))
		{
			return (ft_out_message(ERR_MEM, 0));
		}
		i = -1;
		while (++i < data->rooms_amount)
		{
			data->rooms[i].name = NULL;
			data->rooms[i].is_visit = 0;
		}
	}
	return (1);
}

/*
** Выделение памяти для данных.
** @return указатель н аструктура данных для алгоритма.
*/

t_data	*create_data(void)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
	{
		ft_out_message(ERR_MEM, 0);
		return (0);
	}
	data->is_spaces = 0;
	data->ants_num = 0;
	data->rooms = NULL;
	data->rooms_amount = 0;
	data->start = -1;
	data->end = -1;
	data->connections = NULL;
	return (data);
}
