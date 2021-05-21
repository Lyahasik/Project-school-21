/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:51:02 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/09 17:39:58 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "corewar_struct.h"
#include "corewar.h"

/*
** Отрисовка одного кадра.
** @param vm основная структура алгоритма.
** @param graphic структура графики.
** @param sdl структура отрисовки.
** @return 0 - error, 1 - ok.
*/

int		render_frame(t_vm *vm, t_graphic *graphic, t_sdl *sdl)
{
	if (set_color(sdl, 5) < 0
		|| SDL_RenderClear(sdl->renderer) < 0)
	{
		ft_out_message((char*)SDL_GetError(), 0);
		return (0);
	}
	if (vm->proc_num)
	{
		vm_loop_war(vm);
		if (vm->n_loop_check == vm->n_loop_dead || vm->n_loop_dead <= 0)
			vm_proc_dead(vm);
	}
	if (!put_menu(graphic->sdl, graphic->menu, vm)
		|| !put_field(graphic->sdl, graphic->field))
		return (0);
	SDL_RenderPresent(sdl->renderer);
	return (1);
}

/*
** Цикл отрисовки окна.
** @param graphic структура графики.
** @param sdl структура отрисовки.
*/

void	rendering(t_vm *vm, t_graphic *graphic, t_sdl *sdl)
{
	int			key;
	SDL_Event	event;

	if (!init_players(graphic, vm) || !render_frame(vm, graphic, sdl))
		return ;
	while (!(SDL_PollEvent(&event) && event.type == SDL_QUIT))
	{
		if (!(key = processing_events(vm, graphic, event)))
			break ;
		if (DUMP != -1 && vm->n_loop == DUMP)
			vm->graphic->stop = 1;
		if (graphic->stop != 1)
			if (!render_frame(vm, graphic, sdl))
				break ;
		SDL_Delay(graphic->delay);
	}
}
