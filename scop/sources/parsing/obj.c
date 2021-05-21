/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:40:52 by dhorker           #+#    #+#             */
/*   Updated: 2021/01/16 17:21:28 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int			add_vertex(t_object *object, FILE *file)
{
	t_vec3	*template;
	t_vec3	vertex;
	int		i;

	object->vertex_count++;
	if (!(template = (t_vec3*)malloc(sizeof(t_vec3) * object->vertex_count)))
		return (ft_out_message(ERR_MEM, 0));
	i = 0;
	if (object->vertex != NULL)
	{
		i = -1;
		while (++i < object->vertex_count - 1)
		{
			template[i] = object->vertex[i];
		}
		free(object->vertex);
	}
	if (fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z) != 3)
		return (ft_out_message(ERR_OBJ, 0));
	template[i] = vertex;
	object->vertex = template;
	return (1);
}

static t_triagle	*copy_triagles(t_object *object, int triagle_count)
{
	t_triagle	*template;
	int			i;

	if (!(template =
		(t_triagle*)malloc(sizeof(t_triagle) * object->triagle_count)))
	{
		ft_out_message(ERR_MEM, 0);
		return (NULL);
	}
	i = 0;
	if (object->triagle)
	{
		i = -1;
		while (++i < triagle_count)
		{
			template[i][0].position = object->triagle[i][0].position;
			template[i][1].position = object->triagle[i][1].position;
			template[i][2].position = object->triagle[i][2].position;
			template[i][0].uv = object->triagle[i][0].uv;
			template[i][1].uv = object->triagle[i][1].uv;
			template[i][2].uv = object->triagle[i][2].uv;
		}
	}
	free(object->triagle);
	return (template);
}

static void			create_triagle(t_object *object,
									t_triagle *template, int count, int *ind)
{
	int	i;
	int	step;

	i = object->triagle_count - 3;
	if (count == 3)
		i++;
	step = 0;
	while (++i < object->triagle_count)
	{
		template[i][0].position = object->vertex[ind[step % 4] - 1];
		template[i][1].position = object->vertex[ind[(1 + step) % 4] - 1];
		template[i][2].position = object->vertex[ind[(2 + step) % 4] - 1];
		template[i][0].uv = vec2(0.0f, 0.0f);
		template[i][1].uv = vec2(1.0f, 0.0f);
		template[i][2].uv = vec2(0.0f, 1.0f);
		step += 2;
	}
	object->triagle = template;
}

static int			add_indeces(t_object *object, FILE *file)
{
	t_triagle	*template;
	int			triagle_count;
	int			count;
	int			ind[4];

	count = fscanf(file, "%d %d %d %d\n", &ind[0], &ind[1], &ind[2], &ind[3]);
	if (count != 3 && count != 4)
		return (ft_out_message(ERR_OBJ, 0));
	triagle_count = object->triagle_count;
	object->triagle_count += (count == 4) ? 2 : 1;
	if (!(template = copy_triagles(object, triagle_count)))
		return (0);
	create_triagle(object, template, count, ind);
	return (1);
}

int					read_obj(t_object *object)
{
	FILE			*file;
	unsigned int	shift;
	char			argument[1000];

	if (!(file = fopen(object->obj, "r")))
		return (ft_out_message(ERR_OBJ, 0));
	while (1)
	{
		if (fscanf(file, "%s", argument) == EOF)
			break ;
		if ((!ft_strcmp(argument, "v") && !add_vertex(object, file))
			|| (!ft_strcmp(argument, "f") && !add_indeces(object, file)))
		{
			fclose(file);
			return (0);
		}
	}
	if (fclose(file) == -1)
		return (ft_out_message(ERR_FILE_CLS, 0));
	return (1);
}
