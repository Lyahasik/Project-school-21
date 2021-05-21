/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:31:00 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:25:48 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

/*
** Наложение поворота по оси x.
** @param sin синус.
** @param cos косинус.
** @return матрица поворота.
*/

static void	rotation_x(t_matrix4 *matrix, GLfloat sin, GLfloat cos)
{
	ft_bzero((void*)matrix, sizeof(t_matrix4));
	(*matrix)[0].x = 1;
	(*matrix)[1].y = cos;
	(*matrix)[1].z = sin;
	(*matrix)[2].y = -sin;
	(*matrix)[2].z = cos;
	(*matrix)[3].w = 1;
}

/*
** Наложение поворота по оси y.
** @param sin синус.
** @param cos косинус.
** @return матрица поворота.
*/

static void	rotation_y(t_matrix4 *matrix, GLfloat sin, GLfloat cos)
{
	ft_bzero((void*)matrix, sizeof(t_matrix4));
	(*matrix)[0].x = cos;
	(*matrix)[0].z = -sin;
	(*matrix)[1].y = 1;
	(*matrix)[2].x = sin;
	(*matrix)[2].z = cos;
	(*matrix)[3].w = 1;
}

/*
** Наложение поворота по оси z.
** @param sin синус.
** @param cos косинус.
** @return матрица поворота.
*/

static void	rotation_z(t_matrix4 *matrix, GLfloat sin, GLfloat cos)
{
	ft_bzero((void*)matrix, sizeof(t_matrix4));
	(*matrix)[0].x = cos;
	(*matrix)[0].y = sin;
	(*matrix)[1].x = -sin;
	(*matrix)[1].y = cos;
	(*matrix)[2].z = 1;
	(*matrix)[3].w = 1;
}

/*
** Создание и наложение матриц поворота по углам Эйлера.
** @param m матрица для наложения поворота.
** @param degrees вектор поворота.
** @return матрица поворота.
*/

t_matrix4	*matrix_rotation(t_matrix4 *m, t_vec3 degrees)
{
	t_matrix4	*rotate;
	t_matrix4	*matrix;

	if (!(rotate = (t_matrix4*)malloc(sizeof(t_matrix4)))
		|| !(matrix = (t_matrix4*)malloc(sizeof(t_matrix4))))
	{
		if (rotate)
			free(rotate);
		if (matrix)
			free(matrix);
		ft_out_message(ERR_MEM, 0);
		return (NULL);
	}
	rotation_x(rotate, sin(radians(degrees.x)), cos(radians(degrees.x)));
	matrix_mul4x4(matrix, m, rotate);
	rotation_y(rotate, sin(radians(degrees.y)), cos(radians(degrees.y)));
	matrix_mul4x4(m, matrix, rotate);
	rotation_z(rotate, sin(radians(degrees.z)), cos(radians(degrees.z)));
	matrix_mul4x4(matrix, m, rotate);
	free(rotate);
	return (matrix);
}
