/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:00:08 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 16:55:50 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

/*
** Установка цвета: 1 - red; 2 - green; 3 - blue; 4 - turquoise;
** 5 - dark blue; 6 - grey; 7 - white; 8 - yellow.
** @param sdl структура отрисовки.
** @param color номер цвета.
** @return 0 - ok, иначе номер ошибки.
*/

int	set_color(t_sdl *sdl, int color)
{
	int	error;

	error = 0;
	if (color == 1)
		error = SDL_SetRenderDrawColor(sdl->renderer, RED);
	if (color == 2)
		error = SDL_SetRenderDrawColor(sdl->renderer, GREEN);
	if (color == 3)
		error = SDL_SetRenderDrawColor(sdl->renderer, BLUE);
	if (color == 4)
		error = SDL_SetRenderDrawColor(sdl->renderer, TURQUOISE);
	if (color == 5)
		error = SDL_SetRenderDrawColor(sdl->renderer, DBLUE);
	if (color == 6)
		error = SDL_SetRenderDrawColor(sdl->renderer, GREY);
	if (color == 7)
		error = SDL_SetRenderDrawColor(sdl->renderer, WHITE);
	if (color == 8)
		error = SDL_SetRenderDrawColor(sdl->renderer, YELLOW);
	return (error);
}
