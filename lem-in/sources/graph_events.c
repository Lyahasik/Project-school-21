/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:58:28 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:53:44 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Обработка нажатия кнопки Escape.
** @param event структура с отловленными событиями.
** @return нажата ли кнопка: 0 - yes, 1 - no.
*/

int	event_escape(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			return (0);
	}
	return (1);
}
