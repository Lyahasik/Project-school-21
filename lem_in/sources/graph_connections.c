/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:40:09 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:16:09 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Преобразование координат для отрисовки линии
** относительно масштаба отрисовки.
** @param graphic указатель для работы с данными графики.
** @param vector координаты начала линии.
** @return преобразованные координаты.
*/

static t_vector	scale_line(t_graphic *graphic, t_vector vector)
{
	vector.x = (vector.x * 2) * graphic->scale[graphic->scale_i] +
				graphic->scale[graphic->scale_i];
	vector.y = (vector.y * 2) * graphic->scale[graphic->scale_i] +
				graphic->scale[graphic->scale_i];
	return (vector);
}

/*
** Отрисовка линии пути.
** @param graphic указатель для работы с данными графики.
** @param start координаты начала линии.
** @param end координаты конца линии.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int		put_line(t_graphic *graphic, t_vector start, t_vector end)
{
	int	bold;
	int	step;

	bold = 11 - graphic->scale_i;
	start = scale_line(graphic, start);
	end = scale_line(graphic, end);
	step = -bold;
	while (++step < bold)
	{
		if (SDL_SetRenderDrawColor(graphic->renderer, 123, 87, 49, 255) < 0
			|| (SDL_RenderDrawLine(graphic->renderer,
				start.x + (step / 2), start.y + abs(step) - bold / 2,
				end.x + (step / 2), end.y + abs(step) - bold / 2)) < 0
			|| (SDL_RenderDrawLine(graphic->renderer,
				start.x + (step / 2) - 1, start.y + abs(step) - bold / 2,
				end.x + (step / 2) - 1, end.y + abs(step) - bold / 2)) < 0)
			return (ft_out_message((char*)SDL_GetError(), 0));
	}
	return (1);
}

/*
** Обработка связей комнаты для вывода.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int				put_path(t_graphic *graphic)
{
	t_vector	start;
	t_vector	end;
	int			i;
	int			j;

	i = -1;
	while (++i < graphic->data->rooms_amount)
	{
		j = -1;
		while (++j < graphic->data->rooms_amount)
		{
			if (graphic->data->connections[i][j] == 1)
			{
				start = find_coordinate(graphic->data, i);
				end = find_coordinate(graphic->data, j);
				if (!put_line(graphic, start, end))
					return (0);
			}
		}
	}
	return (1);
}
