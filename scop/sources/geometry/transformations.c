/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:27:13 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/16 18:42:12 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
** Комбинирование матриц трансформаций.
** @param general основная структура данных.
** @param transform структура с матрицами трансформаций.
*/

int		transformations(t_general *general, t_transform transform)
{
	t_matrix4	*model;
	t_matrix4	*view;
	t_matrix4	*projection;
	GLuint		uniform;

	general->object.transform.rotate =
		vec3(0.0f, (GLfloat)glfwGetTime() * 30.0f, 0.0f);
	if (!(model = matrix_model(
					transform.scale, transform.rotate, transform.position))
		|| !(view = look_at(general->camera.position,
			vec3_sum(general->camera.position, vec3(0.0f, 0.0f, -1.0f))))
		|| !(projection = perspective(0.1f, 100.0f)))
	{
		ft_mem_free_args((void*)model, (void*)view, (void*)projection, NULL);
		return (0);
	}
	uniform = glGetUniformLocation(general->shaders.program, "model");
	glUniformMatrix4fv(uniform, 1, GL_FALSE, (GLfloat*)model);
	uniform = glGetUniformLocation(general->shaders.program, "view");
	glUniformMatrix4fv(uniform, 1, GL_FALSE, (GLfloat*)view);
	uniform = glGetUniformLocation(general->shaders.program, "projection");
	glUniformMatrix4fv(uniform, 1, GL_FALSE,
		(GLfloat*)projection);
	ft_mem_free_args((void*)model, (void*)view, (void*)projection, NULL);
	return (1);
}
