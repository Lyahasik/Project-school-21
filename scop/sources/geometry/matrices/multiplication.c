/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:41:08 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:26:23 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

/*
** Умножение матрицы на вектор.
** @param m матрица.
** @param v вектор.
** @return преобразованный вектор.
*/

t_vec4	matrix_mul4x1(t_matrix4 m, t_vec4 v)
{
	t_vec4	vector;

	vector.x = m[0].x * v.x + m[1].x * v.y + m[2].x * v.z + m[3].x * v.w;
	vector.y = m[0].y * v.x + m[1].y * v.y + m[2].y * v.z + m[3].y * v.w;
	vector.z = m[0].z * v.x + m[1].z * v.y + m[2].z * v.z + m[3].z * v.w;
	vector.w = m[0].w * v.x + m[1].w * v.y + m[2].w * v.z + m[3].w * v.w;
	return (vector);
}

/*
** Перемножение матриц.
** @param matrix результирующая матрица.
** @param m1 умножаемая матрица.
** @param m2 умножающая матрица.
*/

void	matrix_mul4x4(t_matrix4 *matrix, t_matrix4 *m1, t_matrix4 *m2)
{
	(*matrix)[0] = matrix_mul4x1(*m1, (*m2)[0]);
	(*matrix)[1] = matrix_mul4x1(*m1, (*m2)[1]);
	(*matrix)[2] = matrix_mul4x1(*m1, (*m2)[2]);
	(*matrix)[3] = matrix_mul4x1(*m1, (*m2)[3]);
}
