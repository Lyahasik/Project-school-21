/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:00:35 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:25:12 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

/*
** Перевод градусов в радианы.
** @param degrees значение угла.
** @return радианы.
*/

GLfloat	radians(float degrees)
{
	return (degrees * (M_PI / 180.0f));
}

/*
** Перевод радиан в градусы.
** @param radians значение радианы.
** @return градусы.
*/

GLfloat	degrees(float radians)
{
	return (radians * (180.0f / M_PI));
}
