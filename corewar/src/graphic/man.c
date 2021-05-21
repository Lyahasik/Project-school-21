/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:51:49 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/28 14:55:05 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

/*
** Вывод длительности задержки.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param dst структура для вывода изображения.
** @param delay индекс задержки: 0 - DELAY_ONE, 1 - DELAY_TWO, 2 - DELAY_THREE.
** @return 0 - error, 1 - ok.
*/

static int	put_delay(t_sdl *sdl, t_menu *menu, SDL_Rect dst, int delay)
{
	dst.x += 90;
	dst.w = 10;
	if (delay == 0)
		if (!put_number(sdl, menu, dst, DELAY_ONE))
			return (0);
	if (delay == 1)
		if (!put_number(sdl, menu, dst, DELAY_TWO))
			return (0);
	if (delay == 2)
		if (!put_number(sdl, menu, dst, DELAY_THREE))
			return (0);
	return (1);
}

/*
** Вывод информации о кнопках.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @return 0 - error, 1 - ok.
*/

int			put_man(t_sdl *sdl, t_menu *menu)
{
	SDL_Rect	dst;
	int			i;

	dst.x = menu->background.x + 30;
	dst.w = 180;
	dst.h = 23;
	i = -1;
	while (++i < 5)
	{
		dst.y = menu->background.y + 560 + (dst.h + 5) * i;
		if (SDL_RenderCopy(sdl->renderer, menu->text[i], NULL, &dst) < 0
			|| !put_delay(sdl, menu, dst, i))
			return (ft_out_message((char*)SDL_GetError(), 0));
	}
	return (1);
}
