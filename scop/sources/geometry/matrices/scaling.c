/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:30:06 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:25:51 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

/*
** Создание матрицы масштабирования.
** @param x множитель по x.
** @param y множитель по y.
** @param z множитель по z.
** @return матрица масштабирования.
*/

t_matrix4	*matrix_scaling(t_vec3 scale)
{
	t_matrix4	*matrix;

	if (!(matrix = (t_matrix4*)malloc(sizeof(t_matrix4))))
	{
		ft_out_message(ERR_MEM, 0);
		return (NULL);
	}
	ft_bzero((void*)matrix, sizeof(t_matrix4));
	(*matrix)[0].x = scale.x;
	(*matrix)[1].y = scale.y;
	(*matrix)[2].z = scale.z;
	(*matrix)[3].w = 1;
	return (matrix);
}
