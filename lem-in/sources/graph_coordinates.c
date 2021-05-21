/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:43:12 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:16:03 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Поиск максимальных координат x и y среди всех комнат.
** @param data указатель для работы с данными алгоритма.
** @return вектор содержащий минимальные координаты.
*/

static t_vector	find_min_coordinate(t_data *data)
{
	int			i;
	t_vector	min;

	min.x = INT_MAX;
	min.y = INT_MAX;
	i = -1;
	while (++i < data->rooms_amount)
	{
		if (data->rooms[i].x < min.x)
			min.x = data->rooms[i].x;
		if (data->rooms[i].y < min.y)
			min.y = data->rooms[i].y;
	}
	return (min);
}

/*
** Поиск минимальных координат x и y среди всех комнат.
** @param data указатель для работы с данными алгоритма.
** @return вектор содержащий максимальные координаты.
*/

static t_vector	find_max_coordinate(t_data *data)
{
	int			i;
	t_vector	max;

	max.x = INT_MIN;
	max.y = INT_MIN;
	i = -1;
	while (++i < data->rooms_amount)
	{
		if (data->rooms[i].x > max.x)
			max.x = data->rooms[i].x;
		if (data->rooms[i].y > max.y)
			max.y = data->rooms[i].y;
	}
	return (max);
}

/*
** Сдвиг координат всех комнат, минимальная оказывается равна 0.
** @param data указатель для работы с данными алгоритма.
** @param min вектор содержащий минимальные координаты x и y.
*/

static void		coordinate_transformation(t_data *data, t_vector min)
{
	int	i;

	i = -1;
	while (++i < data->rooms_amount)
	{
		data->rooms[i].x -= min.x;
		data->rooms[i].y -= min.y;
	}
}

/*
** Расчет масштаба отрисовки комнат и муравьев.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int				calculation_scale(t_graphic *graphic)
{
	t_vector	min;
	t_vector	max;
	int			i;

	min = find_min_coordinate(graphic->data);
	max = find_max_coordinate(graphic->data);
	i = -1;
	while (++i < 11)
	{
		if ((graphic->scale[i] * ((max.x - min.x) * 2 + 1)) >= SIZE_W
			|| (graphic->scale[i] * ((max.y - min.y) * 2 + 1)) >= SIZE_H)
			continue ;
		break ;
	}
	if (i == 11)
		return (ft_out_message(ERR_SCALE, 0));
	graphic->scale_i = i;
	coordinate_transformation(graphic->data, min);
	return (1);
}
