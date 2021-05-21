/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:22:37 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:26:16 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

/*
** Создание матрицы перемещения.
** @param x сдвиг по x.
** @param y сдвиг по y.
** @param z сдвиг по z.
** @return матрица перемещения.
*/

t_matrix4	*matrix_translation(t_vec3 position)
{
	t_matrix4	*matrix;

	if (!(matrix = matrix4_identity()))
		return (NULL);
	(*matrix)[3].x = position.x;
	(*matrix)[3].y = position.y;
	(*matrix)[3].z = position.z;
	return (matrix);
}
