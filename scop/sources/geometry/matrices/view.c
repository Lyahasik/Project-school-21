/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:49:11 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 22:14:41 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

/*
** Создание матрицы вида.
** @param position позиция.
** @param target позиция цели.
** @return матрица вида.
*/

t_matrix4	*look_at(t_vec3 position, t_vec3 target)
{
	t_matrix4	*matrix;
	t_matrix4	*translation;
	t_matrix4	*result;
	t_vec3		axes[3];

	axes[2] = vec3_norm(vec3_sum(position, vec3_inv(target)));
	axes[0] = vec3_norm(vec3_cross(vec3(0.0f, 1.0f, 0.0f), axes[2]));
	axes[1] = vec3_cross(axes[2], axes[0]);
	if (!(translation = matrix_translation(vec3_inv(position)))
		|| !(matrix = matrix4(vec4(axes[0].x, axes[1].x, axes[2].x, 0.0f),
							vec4(axes[0].y, axes[1].y, axes[2].y, 0.0f),
							vec4(axes[0].z, axes[1].z, axes[2].z, 0.0f),
							vec4(0.0f, 0.0f, 0.0f, 1.0f)))
		|| !(result = (t_matrix4*)malloc(sizeof(t_matrix4))))
	{
		ft_mem_free_args(
			(void*)translation, (void*)matrix, (void*)result, NULL);
		return (NULL);
	}
	matrix_mul4x4(result, translation, matrix);
	free(translation);
	free(matrix);
	return (result);
}
