/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:51:02 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 17:06:37 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

/*
** Вывод числа.
** @param sdl структура отрисовки.
** @param menu структура меню.
** @param dst структура для вывода изображения.
** @param number число.
** @return 0 - error, 1 - ok.
*/

int	put_number(t_sdl *sdl, t_menu *menu, SDL_Rect dst, int number)
{
	char		*strnumber;
	int			i;

	if (!(strnumber = ft_itoa(number)))
		return (ft_out_message(ERR_MEM, 0));
	dst.w = 10;
	dst.h = 23;
	i = -1;
	while (strnumber[++i])
	{
		if (SDL_RenderCopy(
			sdl->renderer, menu->figures[strnumber[i] - '0'], NULL, &dst) < 0)
		{
			free(strnumber);
			return (ft_out_message((char*)SDL_GetError(), 0));
		}
		dst.x += dst.w;
	}
	free(strnumber);
	return (1);
}
