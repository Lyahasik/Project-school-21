/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 02:16:35 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 16:59:32 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void	free_sdl(t_sdl *sdl)
{
	if (sdl)
	{
		if (sdl->window)
			SDL_DestroyWindow(sdl->window);
		if (sdl->renderer)
			SDL_DestroyRenderer(sdl->renderer);
		free(sdl);
	}
	SDL_Quit();
}

static void	free_menu(t_menu *menu)
{
	int	i;

	if (menu)
	{
		i = -1;
		while (++i < 16)
		{
			if (menu->operations[i])
				SDL_DestroyTexture(menu->operations[i]);
		}
		i = -1;
		while (++i < 13)
		{
			if (menu->text[i])
				SDL_DestroyTexture(menu->text[i]);
		}
		i = -1;
		while (++i < 10)
		{
			if (menu->figures[i])
				SDL_DestroyTexture(menu->figures[i]);
		}
		free(menu);
	}
}

static void	free_field(t_field *field)
{
	if (field)
	{
		if (field->cells)
		{
			free(field->cells);
		}
		free(field);
	}
}

int			free_graphic(t_graphic *graphic)
{
	if (graphic)
	{
		free_field(graphic->field);
		free_menu(graphic->menu);
		free_sdl(graphic->sdl);
		free(graphic);
	}
	return (0);
}
