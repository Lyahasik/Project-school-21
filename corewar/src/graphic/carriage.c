/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 02:06:15 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 17:26:38 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "../../header/corewar.h"

/*
** Вывод названия операции.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param background структура с позицией отрисовки.
** @param index номер операции 0-15.
** @return 0 - error, 1 - ok.
*/

static int	put_operation(t_sdl *sdl, t_menu *menu, SDL_Rect background,
																	int index)
{
	SDL_Rect	operation;

	operation.x = background.x + 10;
	operation.y = background.y + 37;
	operation.w = 160;
	operation.h = 23;
	if (SDL_RenderCopy(sdl->renderer, menu->text[6], NULL, &operation) < 0)
		return (0);
	operation.x += 90;
	operation.w = 50;
	operation.h = 20;
	if (set_color(sdl, 8) < 0
		|| SDL_RenderFillRect(sdl->renderer, &operation) < 0
		|| SDL_RenderCopy(
			sdl->renderer, menu->operations[index], NULL, &operation) < 0)
	{
		return (ft_out_message((char *)SDL_GetError(), 0));
	}
	return (1);
}

/*
** Вывод позиции каретки.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param background структура с позицией отрисовки.
** @param coord позиция на поле.
** @return 0 - error, 1 - ok.
*/

static int	put_position(t_sdl *sdl, t_menu *menu, SDL_Rect background,
																	int coord)
{
	SDL_Rect	position;

	position.x = background.x + 10;
	position.y = background.y + 60;
	position.w = 160;
	position.h = 23;
	if (SDL_RenderCopy(sdl->renderer, menu->text[7], NULL, &position) < 0)
		return (0);
	position.x += 100;
	position.y += 1;
	position.w = 10;
	if (!put_number(sdl, menu, position, coord))
		return (0);
	return (1);
}

/*
** Вывод данных каретки.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param background структура с позицией отрисовки.
** @return 0 - error, 1 - ok.
*/

int			put_carriage(t_vm *vm, SDL_Rect background, int id_player)
{
	t_sdl	*sdl;
	t_menu	*menu;

	sdl = vm->graphic->sdl;
	menu = vm->graphic->menu;
	if (!put_operation(
			sdl, menu, background, vm->players[id_player].id_op - 1)
		|| !put_position(
			sdl, menu, background, vm->players[id_player].loop_live))
		return (0);
	return (1);
}
