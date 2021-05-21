/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:19:47 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/15 03:35:11 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int	check_program(GLuint program_id)
{
	GLint	error;

	glGetProgramiv(program_id, GL_LINK_STATUS, &error);
	if (!error)
	{
		ft_out_message(ERR_SHDR_PROG, 0);
		return (0);
	}
	return (1);
}

int			create_shader_program(t_shaders *shaders)
{
	if (!create_shader(&shaders->vertex, "shaders/vertex/first.glsl",
			GL_VERTEX_SHADER)
		|| !create_shader(&shaders->fragment, "shaders/fragment/first.glsl",
			GL_FRAGMENT_SHADER))
	{
		return (0);
	}
	shaders->program = glCreateProgram();
	glAttachShader(shaders->program, shaders->vertex.id);
	glAttachShader(shaders->program, shaders->fragment.id);
	glLinkProgram(shaders->program);
	glDeleteShader(shaders->vertex.id);
	glDeleteShader(shaders->fragment.id);
	return (check_program(shaders->program));
}
