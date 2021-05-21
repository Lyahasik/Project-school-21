/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:48:17 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 17:09:43 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static SDL_Texture	*load_image(const char *path, SDL_Renderer *renderer)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (!(surface = SDL_LoadBMP(path)))
	{
		ft_out_message(ERR_IMG_LOAD, 0);
		return (NULL);
	}
	if (!(texture = SDL_CreateTextureFromSurface(renderer, surface)))
	{
		SDL_FreeSurface(surface);
		ft_out_message((char*)SDL_GetError(), 0);
		return (NULL);
	}
	SDL_FreeSurface(surface);
	return (texture);
}

int					init_operations(t_menu *menu, SDL_Renderer *renderer)
{
	if (!(menu->operations[0] = load_image("images/live.bmp", renderer))
		|| !(menu->operations[1] = load_image("images/ld.bmp", renderer))
		|| !(menu->operations[2] = load_image("images/st.bmp", renderer))
		|| !(menu->operations[3] = load_image("images/add.bmp", renderer))
		|| !(menu->operations[4] = load_image("images/sub.bmp", renderer))
		|| !(menu->operations[5] = load_image("images/and.bmp", renderer))
		|| !(menu->operations[6] = load_image("images/or.bmp", renderer))
		|| !(menu->operations[7] = load_image("images/xor.bmp", renderer))
		|| !(menu->operations[8] = load_image("images/zjmp.bmp", renderer))
		|| !(menu->operations[9] = load_image("images/ldi.bmp", renderer))
		|| !(menu->operations[10] = load_image("images/sti.bmp", renderer))
		|| !(menu->operations[11] = load_image("images/fork.bmp", renderer))
		|| !(menu->operations[12] = load_image("images/lld.bmp", renderer))
		|| !(menu->operations[13] = load_image("images/lldi.bmp", renderer))
		|| !(menu->operations[14] = load_image("images/lfork.bmp", renderer))
		|| !(menu->operations[15] = load_image("images/aff.bmp", renderer)))
	{
		return (0);
	}
	return (1);
}

int					init_text(t_menu *menu, SDL_Renderer *renderer)
{
	if (!(menu->text[0] = load_image("images/c.bmp", renderer))
		|| !(menu->text[1] = load_image("images/v.bmp", renderer))
		|| !(menu->text[2] = load_image("images/b.bmp", renderer))
		|| !(menu->text[3] = load_image("images/space.bmp", renderer))
		|| !(menu->text[4] = load_image("images/n.bmp", renderer))
		|| !(menu->text[5] = load_image("images/player.bmp", renderer))
		|| !(menu->text[6] = load_image("images/operation.bmp", renderer))
		|| !(menu->text[7] = load_image("images/cycle_life.bmp", renderer))
		|| !(menu->text[8] = load_image("images/drop.bmp", renderer))
		|| !(menu->text[9] = load_image("images/cycle.bmp", renderer))
		|| !(menu->text[10] = load_image("images/after.bmp", renderer))
		|| !(menu->text[11] = load_image("images/until.bmp", renderer))
		|| !(menu->text[12] = load_image("images/carriages.bmp", renderer)))
	{
		return (0);
	}
	return (1);
}

int					init_figures(t_menu *menu, SDL_Renderer *renderer)
{
	if (!(menu->figures[0] = load_image("images/0.bmp", renderer))
		|| !(menu->figures[1] = load_image("images/1.bmp", renderer))
		|| !(menu->figures[2] = load_image("images/2.bmp", renderer))
		|| !(menu->figures[3] = load_image("images/3.bmp", renderer))
		|| !(menu->figures[4] = load_image("images/4.bmp", renderer))
		|| !(menu->figures[5] = load_image("images/5.bmp", renderer))
		|| !(menu->figures[6] = load_image("images/6.bmp", renderer))
		|| !(menu->figures[7] = load_image("images/7.bmp", renderer))
		|| !(menu->figures[8] = load_image("images/8.bmp", renderer))
		|| !(menu->figures[9] = load_image("images/9.bmp", renderer)))
	{
		return (0);
	}
	return (1);
}
