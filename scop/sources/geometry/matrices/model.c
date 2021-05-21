/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:09:37 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:25:22 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

/*
** Создание матрицы модели.
** @param scale вектор масштаба.
** @param rotate вектор поворота.
** @param position вектор позиции.
** @return матрица модели.
*/

t_matrix4	*matrix_model(t_vec3 scale, t_vec3 rotate, t_vec3 position)
{
	t_matrix4	*model;
	t_matrix4	*mrotate;
	t_matrix4	*mtranslation;

	if (!(model = matrix_scaling(scale))
		|| !(mrotate = matrix_rotation(model, rotate))
		|| !(mtranslation = matrix_translation(position)))
	{
		if (model)
			free(model);
		if (mrotate)
			free(mrotate);
		if (mtranslation)
			free(mtranslation);
		return (NULL);
	}
	matrix_mul4x4(model, mrotate, mtranslation);
	free(mrotate);
	free(mtranslation);
	return (model);
}
