/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:15:31 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/09 16:55:56 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "../../header/corewar.h"

/*
** Вывод заголовка игрока.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param background структура с позицией отрисовки.
** @param number номер игрока.
** @return 0 - error, 1 - ok.
*/

int	put_title(t_sdl *sdl, t_menu *menu, SDL_Rect background, int number)
{
	SDL_Rect	title;

	title.x = background.x + 10;
	title.y = background.y + 7;
	title.w = 160;
	title.h = 23;
	if (SDL_RenderCopy(sdl->renderer, menu->text[5], NULL, &title) < 0)
		return (0);
	title.x += 60;
	title.y += 1;
	title.w = 10;
	if (!put_number(sdl, menu, title, number))
		return (0);
	return (1);
}

/*
** Вывод данных игрока.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param background структура с позицией отрисовки.
** @param number номер игрока.
** @return 0 - error, 1 - ok.
*/

int	put_player(t_vm *vm, SDL_Rect background, int number)
{
	t_sdl		*sdl;
	t_menu		*menu;

	sdl = vm->graphic->sdl;
	menu = vm->graphic->menu;
	if (set_color(sdl, number) < 0
		|| SDL_RenderFillRect(sdl->renderer, &(background)) < 0)
	{
		return (ft_out_message((char*)SDL_GetError(), 0));
	}
	if (!put_title(sdl, menu, background, number)
		|| !put_carriage(vm, background, number - 1))
	{
		return (0);
	}
	return (1);
}

/*
** Начальное заполнение территорий игроков.
** @param graphic структура графики.
** @return 0 - error, 1 - ok.
*/

int	init_players(t_graphic *graphic, t_vm *vm)
{
	int	delta;
	int	i;
	int	j;

	if (vm->players_num > 4)
		return (ft_out_message(ERR_PLRS_NUM, 0));
	delta = MEM_SIZE / vm->players_num;
	if (MEM_SIZE % vm->players_num != 0)
		delta++;
	i = -1;
	while (++i < vm->players_num)
	{
		j = delta * i;
		while (j < MEM_SIZE && j < delta * (i + 1))
		{
			graphic->field->cells[j++].color = i + 1;
		}
	}
	return (1);
}
