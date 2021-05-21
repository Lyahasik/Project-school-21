/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:30 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:15:39 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Инициализация изображения муравья.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	init_ant(t_graphic *graphic)
{
	SDL_Surface	*surface;

	if (!(surface = SDL_LoadBMP("images/ant.bmp")))
	{
		return (ft_out_message(ERR_IMG_ANT, 0));
	}
	if (!(graphic->ant.img =
		SDL_CreateTextureFromSurface(graphic->renderer, surface)))
	{
		SDL_FreeSurface(surface);
		return (ft_out_message(ERR_MEM, 0));
	}
	graphic->ant.height = 165;
	graphic->ant.width = 165;
	SDL_FreeSurface(surface);
	return (1);
}

/*
** Инициализация изображения комнаты.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	init_room(t_graphic *graphic)
{
	SDL_Surface	*surface;

	if (!(surface = SDL_LoadBMP("images/room.bmp")))
	{
		return (ft_out_message(ERR_IMG_ROOM, 0));
	}
	if (!(graphic->room.img =
		SDL_CreateTextureFromSurface(graphic->renderer, surface)))
	{
		SDL_FreeSurface(surface);
		return (ft_out_message(ERR_MEM, 0));
	}
	graphic->room.height = 165;
	graphic->room.width = 165;
	SDL_FreeSurface(surface);
	return (1);
}

/*
** Инициализация фонового изображения.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	init_background(t_graphic *graphic)
{
	SDL_Surface	*surface;

	if (!(surface = SDL_LoadBMP("images/background.bmp")))
	{
		return (ft_out_message(ERR_IMG_BACK, 0));
	}
	if (!(graphic->background =
		SDL_CreateTextureFromSurface(graphic->renderer, surface)))
	{
		SDL_FreeSurface(surface);
		return (ft_out_message(ERR_MEM, 0));
	}
	SDL_FreeSurface(surface);
	return (1);
}
