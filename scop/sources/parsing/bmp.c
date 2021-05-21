/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:46:22 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/15 03:36:50 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static unsigned int	processing_header(FILE *file, t_texture *texture)
{
	char	header[54];

	if (fread(header, 1, 54, file) != 54)
	{
		return (ft_out_message(ERR_BMP, 0));
	}
	if (!(header[0] == 'B' && header[1] == 'M'))
	{
		return (ft_out_message(ERR_BMP, 0));
	}
	texture->size = *(int*)(&header[0x22]);
	texture->width = *(int*)(&header[0x12]);
	texture->height = *(int*)(&header[0x16]);
	return (*(int*)(&header[0x0A]));
}

static int			processing_data(FILE *file,
								t_texture *texture,
								unsigned int shift)
{
	unsigned char	*temp;

	if (texture->size == 0)
		texture->size = texture->width * texture->height * 3;
	if (shift != 0)
		shift -= 54;
	if (!(temp = (unsigned char*)ft_strnew(texture->size + shift)))
	{
		return (ft_out_message(ERR_MEM, 0));
	}
	if (!(texture->image = (unsigned char*)ft_strnew(texture->size)))
	{
		free(temp);
		return (ft_out_message(ERR_MEM, 0));
	}
	fread(temp, 1, texture->size, file);
	texture->image = ft_memcpy(texture->image, temp + shift, texture->size);
	free(temp);
	return (1);
}

int					read_bmp(const char *path, t_texture *texture)
{
	FILE			*file;
	unsigned int	shift;

	if (!(file = fopen(path, "rb")))
	{
		return (ft_out_message(ERR_BMP, 0));
	}
	if (!(shift = processing_header(file, texture))
		|| !processing_data(file, texture, shift))
	{
		if (fclose(file) == -1)
			ft_out_message(ERR_FILE_CLS, 0);
		return (0);
	}
	if (fclose(file) == -1)
	{
		return (ft_out_message(ERR_FILE_CLS, 0));
	}
	return (1);
}
