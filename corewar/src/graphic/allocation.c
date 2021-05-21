/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 20:22:08 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 16:56:20 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

/*
** Выделение памяти для структуры графики.
** Заполнение данными по-умолчанию.
** @return структура графики.
*/

t_graphic	*allocation_graphic(void)
{
	t_graphic	*graphic;

	if (!(graphic = (t_graphic*)malloc(sizeof(t_graphic))))
	{
		ft_out_message(ERR_MEM, 0);
		return (NULL);
	}
	graphic->sdl = NULL;
	graphic->menu = NULL;
	graphic->field = NULL;
	return (graphic);
}

/*
** Выделение памяти для структуры sdl.
** Заполнение данными по-умолчанию.
** @return структура sdl.
*/

t_sdl		*allocation_sdl(void)
{
	t_sdl	*sdl;

	if (!(sdl = (t_sdl*)malloc(sizeof(t_sdl))))
	{
		ft_out_message(ERR_MEM, 0);
		return (NULL);
	}
	sdl->renderer = NULL;
	sdl->window = NULL;
	return (sdl);
}

/*
** Выделение памяти для структуры меню.
** Заполнение данными по-умолчанию.
** @return структура меню.
*/

t_menu		*allocation_menu(void)
{
	t_menu	*menu;
	int		i;

	if (!(menu = (t_menu*)malloc(sizeof(t_menu))))
	{
		ft_out_message(ERR_MEM, 0);
		return (NULL);
	}
	i = -1;
	while (++i < 16)
		menu->operations[i] = NULL;
	i = -1;
	while (++i < 13)
		menu->text[i] = NULL;
	i = -1;
	while (++i < 10)
		menu->figures[i] = NULL;
	return (menu);
}

/*
** Выделение памяти для структуры поля.
** Заполнение данными по-умолчанию.
** @return структура поля.
*/

t_field		*allocation_field(void)
{
	t_field	*field;

	if (!(field = (t_field*)malloc(sizeof(t_field))))
	{
		ft_out_message(ERR_MEM, 0);
		return (NULL);
	}
	field->cells = NULL;
	return (field);
}
