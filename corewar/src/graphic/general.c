/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:11:55 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 17:05:19 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "../../header/corewar.h"

/*
** Вывод общее количество циклов.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param general структура с координатами и размерами изображения.
** @return 0 - error, 1 - ok.
*/

static int	put_cycle(t_sdl *sdl, t_menu *menu, SDL_Rect general, int value)
{
	if (SDL_RenderCopy(sdl->renderer, menu->text[9], NULL, &general) < 0)
		return (ft_out_message((char*)SDL_GetError(), 0));
	general.x += 50;
	if (!put_number(sdl, menu, general, value))
		return (0);
	return (1);
}

/*
** Вывод количество циклов с крайней проверки.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param general структура с координатами и размерами изображения.
** @return 0 - error, 1 - ok.
*/

static int	put_after(t_sdl *sdl, t_menu *menu, SDL_Rect general, int value)
{
	general.y += 33;
	if (SDL_RenderCopy(sdl->renderer, menu->text[10], NULL, &general) < 0)
		return (ft_out_message((char*)SDL_GetError(), 0));
	general.x += 128;
	if (!put_number(sdl, menu, general, value))
		return (0);
	return (1);
}

/*
** Вывод количества циклов до проверки.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param general структура с координатами и размерами изображения.
** @return 0 - error, 1 - ok.
*/

static int	put_until(t_sdl *sdl, t_menu *menu, SDL_Rect general, int value)
{
	general.y += 66;
	if (SDL_RenderCopy(sdl->renderer, menu->text[11], NULL, &general) < 0)
		return (ft_out_message((char*)SDL_GetError(), 0));
	general.x += 141;
	if (!put_number(sdl, menu, general, value))
		return (0);
	return (1);
}

/*
** Вывод количества кареток.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param general структура с координатами и размерами изображения.
** @return 0 - error, 1 - ok.
*/

static int	put_carriages(t_sdl *sdl, t_menu *menu, SDL_Rect general, int value)
{
	general.y += 99;
	if (SDL_RenderCopy(sdl->renderer, menu->text[12], NULL, &general) < 0)
		return (ft_out_message((char*)SDL_GetError(), 0));
	general.x += 85;
	if (!put_number(sdl, menu, general, value))
		return (0);
	return (1);
}

/*
** Вывод общей информации о поле.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @return 0 - error, 1 - ok.
*/

int			put_general(t_sdl *sdl, t_menu *menu, t_vm *vm)
{
	SDL_Rect	general;

	general.x = menu->background.x + 30;
	general.y = menu->background.y + 15;
	general.w = 140;
	general.h = 23;
	if (!put_cycle(sdl, menu, general, vm->n_loop)
		|| !put_after(sdl, menu, general, vm->n_loop_check)
		|| !put_until(sdl, menu, general, vm->n_loop_dead)
		|| !put_carriages(sdl, menu, general, vm->proc_num))
		return (0);
	return (1);
}
