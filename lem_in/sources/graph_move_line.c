/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:52:46 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:52:52 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Расчет следующего положения на линии шага.
** @param start координаты текущего пикселя.
** @param end координаты пикселя назначения.
** @return координаты следующей позиции муравья.
*/

static t_vector	find_shift(t_vector start, t_vector end)
{
	t_vector	delta;
	t_vector	sign;
	int			error;
	int			error2;
	int			size;

	size = 10;
	delta = create_vector(abs(end.x - start.x), abs(end.y - start.y));
	sign =
		create_vector((start.x < end.x) ? 1 : -1, (start.y < end.y) ? 1 : -1);
	error = delta.x - delta.y;
	while (--size >= 0 && (start.x != end.x || start.y != end.y))
	{
		if ((error2 = error * 2) > -delta.y)
		{
			error -= delta.y;
			start.x += sign.x;
		}
		if (error2 < delta.x)
		{
			error += delta.x;
			start.y += sign.y;
		}
	}
	return (start);
}

/*
** Вывод процесса перемещения между комнатами.
** @param graphic указатель для работы с данными графики.
** @param ant массив всех муравьев.
** @param current комната из которой перемещается муравей.
** @param destination комната в которую перемещается муравей.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int				put_shift(t_graphic *graphic, t_ant *ant, t_room current,
						t_room destination)
{
	if (equals_vector(ant->position, create_vector(-1, -1)))
	{
		ant->position = create_vector(
			scale_point(graphic, current.x),
			scale_point(graphic, current.y));
		ant->destination = create_vector(
			scale_point(graphic, destination.x),
			scale_point(graphic, destination.y));
	}
	if (!(put_ant(graphic, graphic->ant, ant->position)))
		return (0);
	ant->position = find_shift(ant->position, ant->destination);
	return (1);
}
