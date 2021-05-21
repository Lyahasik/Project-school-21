/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:25:50 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/16 15:21:02 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	create_vbo(t_object *object)
{
	glGenBuffers(1, &object->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, object->vbo);
	glBufferData(GL_ARRAY_BUFFER, object->triagle_count * sizeof(t_triagle),
		object->triagle, GL_STATIC_DRAW);
}

static void	create_vao(t_object *object)
{
	read_bmp(object->bmp, &object->texture);
	glGenTextures(1, &object->texture.id);
	glBindTexture(GL_TEXTURE_2D, object->texture.id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, object->texture.width,
	object->texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, object->texture.image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenVertexArrays(1, &object->vao);
	glBindVertexArray(object->vao);
	glVertexAttribPointer(
		0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
		(GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindTexture(GL_TEXTURE_2D, object->texture.id);
	glBindVertexArray(object->vao);
	glDrawElements(GL_TRIANGLES, 5, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

int			create_object(t_object *object)
{
	int	i;

	if (!read_obj(object))
		return (0);
	create_vbo(object);
	create_vao(object);
	object->transform.rotate = vec3(0.0f, 0.0f, 0.0f);
	object->transform.scale = vec3(1.0f, 1.0f, 1.0f);
	update_center(object);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return (1);
}
