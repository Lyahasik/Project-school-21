/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:27:03 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:12:09 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Получение координат комнаты.
** @param data указатель для работы с данными алгоритма.
** @param room номер комнаты.
** @return координаты комнаты.
*/

t_vector	find_coordinate(t_data *data, int room)
{
	t_vector	coordinate;

	coordinate.x = data->rooms[room].x;
	coordinate.y = data->rooms[room].y;
	return (coordinate);
}

/*
** Вызов отрисовки всех комнат.
** @param graphic указатель для работы с данными графики.
** @param rooms структура содержащая все комнаты.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			put_rooms(t_graphic *graphic, t_room *rooms)
{
	int	i;

	i = -1;
	while (++i < graphic->data->rooms_amount)
	{
		if (!(put_image(graphic, graphic->room, rooms[i].x, rooms[i].y)))
		{
			return (0);
		}
	}
	return (1);
}

/*
** Поиск комнаты в списке.
** @param data указатель для работы с данными алгоритма.
** @param ant данные шага муравья.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			find_room(t_data *data, char **ant)
{
	int	i;

	if (ant[1])
	{
		i = -1;
		while (++i < data->rooms_amount)
		{
			if (!ft_strcmp(data->rooms[i].name, ant[1]))
				return (i);
		}
	}
	return (ft_out_message(ERR_ROOM_NAME, -1));
}
