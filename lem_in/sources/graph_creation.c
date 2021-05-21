/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:32:36 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/05 20:38:13 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Создание массива шагов.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			create_steps(t_graphic *graphic)
{
	int	i;

	if (!(graphic->steps =
		(t_ant**)malloc(sizeof(t_ant*) * graphic->steps_amount))
		|| !(graphic->step_ants_amount =
		(int*)malloc(sizeof(int) * graphic->steps_amount)))
		return (ft_out_message(ERR_MEM, 0));
	i = -1;
	while (++i < graphic->steps_amount)
	{
		graphic->steps[i] = NULL;
	}
	return (1);
}

/*
** Создание массива данных для муравьев.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			create_ants(t_graphic *graphic)
{
	int	i;

	if (!(graphic->ants =
		(t_ant*)malloc(sizeof(t_ant) * graphic->data->ants_num)))
		return (ft_out_message(ERR_MEM, 0));
	i = -1;
	while (++i < graphic->data->ants_num)
	{
		graphic->ants[i].name = NULL;
		graphic->ants[i].position.x = -1;
		graphic->ants[i].position.y = -1;
		graphic->ants[i].room_current = graphic->data->start;
		graphic->ants[i].room_destination = -1;
	}
	return (1);
}

/*
** Создание массива масштабов изображений.
** @param graphic указатель для работы с данными графики.
*/

static void	create_scale(t_graphic *graphic)
{
	graphic->scale[0] = 180;
	graphic->scale[1] = 120;
	graphic->scale[2] = 90;
	graphic->scale[3] = 72;
	graphic->scale[4] = 60;
	graphic->scale[5] = 45;
	graphic->scale[6] = 40;
	graphic->scale[7] = 36;
	graphic->scale[8] = 30;
	graphic->scale[9] = 24;
	graphic->scale[10] = 20;
}

/*
** Создание/заполнение структуры для работы с графикой.
** @return указатель на структуру данных для графики.
*/

t_graphic	*create_graphic(void)
{
	t_graphic	*graphic;

	if (!(graphic = (t_graphic*)malloc(sizeof(t_graphic))))
	{
		ft_out_message(ERR_MEM, 0);
		return (0);
	}
	if (!(graphic->data = create_data()))
	{
		ft_out_message(ERR_MEM, 0);
		return (0);
	}
	create_scale(graphic);
	graphic->steps = NULL;
	graphic->step_ants_amount = NULL;
	graphic->ants = NULL;
	graphic->window = NULL;
	graphic->renderer = NULL;
	graphic->background = NULL;
	graphic->ant.img = NULL;
	graphic->room.img = NULL;
	return (graphic);
}
