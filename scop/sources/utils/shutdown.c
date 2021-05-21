/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:04:02 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/16 17:26:52 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	free_glfw(t_glfw *glfw)
{
	if (glfw)
	{
		if (glfw->window)
		{
			glfwDestroyWindow(glfw->window);
		}
		free(glfw);
	}
}

static void	free_shader(t_shader *shader)
{
	if (shader->code)
	{
		free((char*)shader->code);
	}
}

static void	free_object(t_object *object)
{
	if (object->texture.image)
	{
		free(object->texture.image);
	}
	if (object->triagle)
	{
		free(object->triagle);
	}
	if (object->vertex)
	{
		free(object->vertex);
	}
	if (object->uv)
	{
		free(object->uv);
	}
}

int			shutdown(t_general *general)
{
	free_glfw(general->glfw);
	free_shader(&general->shaders.vertex);
	free_shader(&general->shaders.fragment);
	free_object(&general->object);
	return (0);
}
