/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:59:50 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:38:39 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Очистка памяти для комнат.
** @param data указатель для работы с данными алгоритма.
** @return 0.
*/

static int	free_rooms(t_data *data)
{
	int	i;

	if (data->rooms != NULL)
	{
		i = -1;
		while (++i < data->rooms_amount)
		{
			if (data->rooms[i].name != NULL)
			{
				free(data->rooms[i].name);
			}
		}
		free(data->rooms);
	}
	return (0);
}

/*
** Очистка памяти для матрицы связей.
** @param data указатель для работы с данными алгоритма.
** @return 0.
*/

static int	free_connections(t_data *data)
{
	int	i;

	if (data->connections != NULL)
	{
		i = -1;
		while (++i < data->rooms_amount && data->connections[i] != NULL)
		{
			free(data->connections[i]);
		}
		free(data->connections);
	}
	return (0);
}

/*
** Очистка памяти для данных алгоритма.
** @param data указатель для работы с данными алгоритма.
** @return 0.
*/

int			free_data(t_data *data)
{
	if (data != NULL)
	{
		free_rooms(data);
		free_connections(data);
		free(data);
	}
	return (0);
}
