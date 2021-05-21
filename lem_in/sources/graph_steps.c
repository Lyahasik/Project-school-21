/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:47:49 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:52:32 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Вывод муравьев в первой и последней комнатах.
** @param graphic указатель для работы с данными графики.
** @param data указатель для работы с данными алгоритма.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	put_ant_start(t_graphic *graphic, t_data *data)
{
	if (graphic->ants[data->ants_num - 1].room_destination == -1)
	{
		if (!(put_image(graphic, graphic->ant,
			data->rooms[data->start].x, data->rooms[data->start].y)))
			return (0);
	}
	if (equals_vector(graphic->ants[0].position, create_vector(
				scale_point(graphic, data->rooms[data->end].x),
				scale_point(graphic, data->rooms[data->end].y))))
	{
		if (!(put_image(graphic, graphic->ant,
			data->rooms[data->end].x, data->rooms[data->end].y)))
			return (0);
	}
	return (1);
}

/*
** Обновление номера шага если все муравьи оказались в комнатах назначения.
** @param graphic указатель для работы с данными графики.
** @param step номер обрабатываемого шага.
*/

static void	update_step(t_graphic *graphic, int *step)
{
	int	i;
	int	j;

	i = -1;
	while (++i < graphic->step_ants_amount[*step])
	{
		j = -1;
		while (++j < graphic->data->ants_num)
		{
			if (!ft_strcmp(graphic->ants[j].name,
							graphic->steps[*step][i].name))
			{
				if (!equals_vector(graphic->ants[j].position,
					graphic->ants[j].destination))
					return ;
				break ;
			}
		}
	}
	(*step)++;
}

/*
** Вывод процесса перемещения между комнатами.
** @param graphic указатель для работы с данными графики.
** @param rooms массив всех комнат.
** @param step номер обрабатываемого шага.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	put_step(t_graphic *graphic, t_room *rooms, int *step)
{
	int		i;
	t_ant	*ant;
	int		dest;

	i = -1;
	while (++i < graphic->step_ants_amount[*step])
	{
		dest = graphic->steps[*step][i].room_destination;
		ant = find_ant(graphic, graphic->steps[*step][i].name);
		ant->room_destination = dest;
		if (equals_vector(ant->position, ant->destination))
		{
			ant->room_current = dest;
			ant->destination = create_vector(
				scale_point(graphic, rooms[dest].x),
				scale_point(graphic, rooms[dest].y));
			if (!(put_ant(graphic, graphic->ant, ant->position)))
				return (0);
		}
		else if (!put_shift(graphic, ant, rooms[ant->room_current],
			rooms[dest]))
			return (0);
	}
	update_step(graphic, step);
	return (1);
}

/*
** Обновление списка муравьев делающих шаг.
** @param graphic указатель для работы с данными графики.
** @param step номер обрабатываемого шага.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	update_ants(t_graphic *graphic, int step)
{
	int	i;
	int	j;

	i = -1;
	while (++i < graphic->step_ants_amount[step])
	{
		j = -1;
		while (++j < graphic->data->ants_num)
		{
			if (graphic->ants[j].name == NULL)
			{
				if (!(graphic->ants[j].name =
					ft_strdup(graphic->steps[step][i].name)))
					return (ft_out_message(ERR_MEM, 0));
				graphic->ants[i].room_destination =
					graphic->steps[step][i].room_destination;
				break ;
			}
			else if (!ft_strcmp(graphic->ants[j].name,
				graphic->steps[step][i].name))
				break ;
		}
	}
	return (1);
}

/*
** Проход по всем шагам для вывода.
** @param graphic указатель для работы с данными графики.
** @param step номер обрабатываемого шага.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			put_steps(t_graphic *graphic, int *step)
{
	if (*step < graphic->steps_amount)
	{
		if (!update_ants(graphic, *step)
			|| !put_step(graphic, graphic->data->rooms, step))
			return (0);
	}
	else
	{
		if (!(put_image(graphic, graphic->ant,
			graphic->data->rooms[graphic->data->end].x,
			graphic->data->rooms[graphic->data->end].y)))
			return (0);
	}
	if (!put_ant_start(graphic, graphic->data))
		return (0);
	return (1);
}
