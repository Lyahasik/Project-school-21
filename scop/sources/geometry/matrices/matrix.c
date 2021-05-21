/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:42:52 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:27:49 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

/*
** Создание матрицы. Вектор соответствует одной колонке матрицы.
** @param column1 1 вектор.
** @param column2 2 вектор.
** @param column3 3 вектор.
** @param column4 4 вектор.
** @return матрица.
*/

t_matrix4	*matrix4(t_vec4 column1,
						t_vec4 column2,
						t_vec4 column3,
						t_vec4 column4)
{
	t_matrix4	*matrix;

	if (!(matrix = (t_matrix4*)malloc(sizeof(t_matrix4))))
	{
		ft_out_message(ERR_MEM, 0);
		return (NULL);
	}
	(*matrix)[0].x = column1.x;
	(*matrix)[0].y = column1.y;
	(*matrix)[0].z = column1.z;
	(*matrix)[0].w = column1.w;
	(*matrix)[1].x = column2.x;
	(*matrix)[1].y = column2.y;
	(*matrix)[1].z = column2.z;
	(*matrix)[1].w = column2.w;
	(*matrix)[2].x = column3.x;
	(*matrix)[2].y = column3.y;
	(*matrix)[2].z = column3.z;
	(*matrix)[2].w = column3.w;
	(*matrix)[3].x = column4.x;
	(*matrix)[3].y = column4.y;
	(*matrix)[3].z = column4.z;
	(*matrix)[3].w = column4.w;
	return (matrix);
}

/*
** Создание единичной матрицы.
** @return единичная матрица.
*/

t_matrix4	*matrix4_identity(void)
{
	t_matrix4	*matrix;

	if (!(matrix = (t_matrix4*)malloc(sizeof(t_matrix4))))
	{
		ft_out_message(ERR_MEM, 0);
		return (NULL);
	}
	ft_bzero((void*)matrix, sizeof(t_matrix4));
	(*matrix)[0].x = 1;
	(*matrix)[1].y = 1;
	(*matrix)[2].z = 1;
	(*matrix)[3].w = 1;
	return (matrix);
}
