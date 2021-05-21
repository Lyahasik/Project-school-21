/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:50:23 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:25:41 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "scop.h"

/*
** Создание матрицы перспецтивы.
** @param near ближняя граница отображения.
** @param far дальняя граница отображения.
** @return матрица перспективы.
*/

t_matrix4	*perspective(float near, float far)
{
	t_matrix4	*perspected;
	float		half;
	float		aspect;

	aspect = (GLfloat)SIZE_W / (GLfloat)SIZE_H;
	half = (GLfloat)tanf(radians((FOV) / 2.0f));
	if (!(perspected = matrix4_identity()))
		return (NULL);
	(*perspected)[0].x = 1.0f / (aspect * half);
	(*perspected)[1].y = 1.0f / (half);
	(*perspected)[2].z = -(far + near) / (far - near);
	(*perspected)[2].w = -1.0f;
	(*perspected)[3].z = -2 * far * near / (far - near);
	(*perspected)[3].w = 0.0f;
	return (perspected);
}
