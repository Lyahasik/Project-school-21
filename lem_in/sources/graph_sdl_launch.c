/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:33:25 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:14:59 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Инициализация данных для вывода.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	sdl_launch(t_graphic *graphic)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0
		|| !(graphic->window = SDL_CreateWindow("Lem-in",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_W, SIZE_H, 0))
		|| !(graphic->renderer = SDL_CreateRenderer(graphic->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		return (ft_out_message(ERR_SDL_INIT, 0));
	}
	if (!init_background(graphic) || !init_ant(graphic) || !init_room(graphic))
	{
		return (0);
	}
	SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
	return (1);
}

/*
** Вывод изображения в реальном времени.
** @param graphic указатель для работы с данными графики.
** @return завершение операции.
*/

int			window_launch(t_graphic *graphic)
{
	SDL_Event	event;
	int			step;

	if (!(sdl_launch(graphic)))
		return (0);
	step = 0;
	while (!(SDL_PollEvent(&event) && event.type == SDL_QUIT))
	{
		if ((SDL_SetRenderDrawColor(graphic->renderer, 255, 150, 150, 255) < 0)
			|| SDL_RenderClear(graphic->renderer) < 0
			|| !put_background(graphic)
			|| !put_path(graphic) || !put_rooms(graphic, graphic->data->rooms)
			|| !put_steps(graphic, &step) || !event_escape(event))
			break ;
		SDL_Delay(50);
		SDL_RenderPresent(graphic->renderer);
	}
	return (0);
}
