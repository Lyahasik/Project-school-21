/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:52:18 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 17:06:21 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "corewar.h"

/*
** Вывод участников боя.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @return 0 - error, 1 - ok.
*/

int	put_players(t_vm *vm)
{
	SDL_Rect	background;
	int			i;
	t_sdl		*sdl;
	t_menu		*menu;

	sdl = vm->graphic->sdl;
	menu = vm->graphic->menu;
	background.x = menu->background.x;
	background.y = menu->background.y + 150;
	background.w = menu->background.w;
	background.h = 100;
	i = -1;
	while (++i < vm->players_num)
	{
		if (!put_player(vm, background, i + 1))
			return (0);
		background.y += background.h;
	}
	return (1);
}

/*
** Вывод меню.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @return 0 - error, 1 - ok.
*/

int	put_menu(t_sdl *sdl, t_menu *menu, t_vm *vm)
{
	if (set_color(sdl, 6) < 0
		|| SDL_RenderFillRect(sdl->renderer, &(menu->background)) < 0)
	{
		return (ft_out_message((char*)SDL_GetError(), 0));
	}
	if (!put_man(sdl, menu) || !put_players(vm)
		|| !put_general(sdl, menu, vm))
	{
		return (0);
	}
	return (1);
}
