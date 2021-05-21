/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:37:43 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:15:10 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Преобразование координаты позиции относительно масштаба сортировки.
** @param graphic указатель для работы с данными графики.
** @param number координата.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	scale_point(t_graphic *graphic, int number)
{
	return ((number + number) * graphic->scale[graphic->scale_i] +
			graphic->scale[graphic->scale_i] / 2);
}

/*
** Вывод изображения муравья.
** @param graphic указатель для работы с данными графики.
** @param img структура хранящая данные изображения.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	put_ant(t_graphic *graphic, t_img img, t_vector point)
{
	SDL_Rect	dst;
	SDL_Rect	src;

	src.x = 0;
	src.y = 0;
	src.w = img.width;
	src.h = img.height;
	dst.x = point.x;
	dst.y = point.y;
	dst.w = graphic->scale[graphic->scale_i];
	dst.h = graphic->scale[graphic->scale_i];
	if (SDL_RenderCopy(graphic->renderer, img.img, &src, &dst) < 0)
		return (ft_out_message((char*)SDL_GetError(), 0));
	return (1);
}

/*
** Вывод изображения комнаты/муравья.
** @param graphic указатель для работы с данными графики.
** @param img структура хранящая данные изображения.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	put_image(t_graphic *graphic, t_img img, int x, int y)
{
	SDL_Rect	dst;
	SDL_Rect	src;

	src.x = 0;
	src.y = 0;
	src.w = img.width;
	src.h = img.height;
	dst.x = scale_point(graphic, x);
	dst.y = scale_point(graphic, y);
	dst.w = graphic->scale[graphic->scale_i];
	dst.h = graphic->scale[graphic->scale_i];
	if (SDL_RenderCopy(graphic->renderer, img.img, &src, &dst) < 0)
		return (ft_out_message((char*)SDL_GetError(), 0));
	return (1);
}

/*
** Вывод фонового изображения.
** @param graphic указатель для работы с данными графики.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	put_background(t_graphic *graphic)
{
	if (SDL_RenderCopy(graphic->renderer, graphic->background, NULL, NULL) < 0)
	{
		return (ft_out_message((char*)SDL_GetError(), 0));
	}
	return (1);
}
