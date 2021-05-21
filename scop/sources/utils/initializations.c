/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:08:33 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/16 17:27:14 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		init_glew(t_general *general)
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		return (ft_out_message(ERR_GLEW_INIT, 0));
	}
	glfwSetInputMode(general->glfw->window, GLFW_STICKY_KEYS, GL_TRUE);
	return (1);
}

int		init_glfw(t_general *general)
{
	t_glfw	*glfw;

	if (!(general->glfw = (t_glfw*)malloc(sizeof(t_glfw))))
	{
		return (ft_out_message(ERR_MEM, 0));
	}
	glfw = general->glfw;
	if (!glfwInit())
	{
		return (ft_out_message(ERR_GLFW_INIT, 0));
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (!(glfw->window = glfwCreateWindow(SIZE_W, SIZE_H, "SCOP", NULL, NULL)))
	{
		glfwTerminate();
		return (ft_out_message(ERR_GLFW_WIN, 0));
	}
	glfwMakeContextCurrent(glfw->window);
	return (1);
}

void	init_general(t_general *general)
{
	general->glfw = NULL;
	general->shaders.vertex.code = NULL;
	general->shaders.fragment.code = NULL;
	general->shaders.red = 1.0f;
	general->object.texture.image = NULL;
	general->object.triagle = NULL;
	general->object.triagle_count = 0;
	general->object.vertex = NULL;
	general->object.vertex_count = 0;
	general->object.uv = NULL;
	general->object.uv_count = 0;
}
