/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:50:07 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/15 04:49:03 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			color_change(t_shaders *shaders)
{
	GLuint uniform;

	if (shaders->change == 0)
	{
		if (shaders->red < 1.0f)
			shaders->red += 0.01f;
	}
	else if (shaders->change == 1)
	{
		if (shaders->red > 0.0f)
			shaders->red -= 0.01f;
	}
	uniform = glGetUniformLocation(shaders->program, "red");
	glUniform1f(uniform, shaders->red);
}

static int		check_shader(GLuint shader_id, int type)
{
	GLint error;

	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &error);
	if (!error)
	{
		if (type == GL_VERTEX_SHADER)
			return (ft_out_message(ERR_SHDR_VRTX, 0));
		if (type == GL_FRAGMENT_SHADER)
			return (ft_out_message(ERR_SHDR_FRGM, 0));
	}
	return (1);
}

static	char	*read_file(const char *path)
{
	int		fd;
	int		bytes;
	char	*code;

	code = ft_strnew(BUFF_CODE);
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_out_message(ERR_SHDR_PATH, 0);
		return (NULL);
	}
	if ((bytes = read(fd, code, BUFF_CODE)) == -1)
	{
		ft_out_message(ERR_SHDR_READ, 0);
		return (NULL);
	}
	code[bytes] = '\0';
	if (close(fd) == -1)
	{
		ft_out_message(ERR_FILE_CLS, 0);
		return (NULL);
	}
	return (code);
}

int				create_shader(t_shader *shader, const char *path, int type)
{
	if (!(shader->code = (const GLchar *)read_file(path)))
	{
		return (0);
	}
	shader->id = glCreateShader(type);
	glShaderSource(shader->id, 1, &shader->code, NULL);
	glCompileShader(shader->id);
	return (check_shader(shader->id, type));
}
