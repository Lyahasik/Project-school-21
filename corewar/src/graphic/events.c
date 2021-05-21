/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:52:59 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 16:56:01 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "corewar_struct.h"
#include "corewar.h"

/*
** Обработка нажатий.
** @param event структура с отловленными событиями.
** @return 0 - Escape, 2 - N.
*/

int	processing_events(t_vm *vm, t_graphic *graphic, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			return (0);
		if (event.key.keysym.scancode == SDL_SCANCODE_N)
		{
			if (!render_frame(vm, graphic, graphic->sdl))
				return (0);
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_C)
			graphic->delay = DELAY_ONE;
		if (event.key.keysym.scancode == SDL_SCANCODE_V)
			graphic->delay = DELAY_TWO;
		if (event.key.keysym.scancode == SDL_SCANCODE_B)
			graphic->delay = DELAY_THREE;
		if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
			graphic->stop = (graphic->stop == 0) ? 1 : 0;
	}
	return (1);
}
