/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_init_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:24:22 by jsprouts          #+#    #+#             */
/*   Updated: 2020/11/15 17:44:12 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_room(t_data *data, t_paths *paths, int i, int *count_end)
{
	paths->path->next = (t_cont*)ft_palloc(sizeof(t_cont));
	paths->path->next->id = i;
	if (data->end == i)
	{
		(*count_end)++;
	}
	paths->path->next->prev = paths->path;
	paths->path = paths->path->next;
	paths->path->next = NULL;
	paths->size = paths->size + data->connections[paths->path->prev->id][i];
	data->rooms[i].id_path = paths->id_path;
}

void	create_new_path(t_data *data, t_paths *paths, int room, int *count_end)
{
	t_paths	*new;
	t_cont	*buff;

	new = (t_paths*)ft_palloc(sizeof(t_paths));
	buff = paths->start;
	new->next = NULL;
	new->id_path = data->id_path++;
	new->path = (t_cont*)ft_palloc(sizeof(t_cont));
	new->path->prev = NULL;
	new->path->id = buff->id;
	new->start = new->path;
	while (buff->next->next != NULL)
	{
		new->path->next = (t_cont*)ft_palloc(sizeof(t_cont));
		new->path->next->prev = new->path;
		new->path->next->next = NULL;
		new->path->next->id = buff->next->id;
		new->path = new->path->next;
		buff = buff->next;
	}
	new->prev = data->last_path;
	data->last_path->next = new;
	data->last_path = new;
	add_room(data, new, room, count_end);
	new->size = paths->size;
}

t_paths	*init(int id_path, int room, t_data *data)
{
	t_paths *paths;

	paths = (t_paths*)ft_palloc(sizeof(t_paths));
	paths->path = (t_cont*)ft_palloc(sizeof(t_cont));
	paths->path->prev = (t_cont*)ft_palloc(sizeof(t_cont));
	paths->path->prev->id = data->start;
	paths->start = paths->path->prev;
	paths->path->prev->prev = NULL;
	paths->path->prev->next = paths->path;
	paths->path->id = room;
	paths->path->next = NULL;
	paths->id_path = id_path;
	data->rooms[room].id_path = id_path;
	paths->size = 1;
	paths->next = NULL;
	paths->prev = NULL;
	return (paths);
}

void	create_path(t_data *data, t_paths **paths, int room, t_paths **start)
{
	if ((*paths) == NULL)
	{
		(*paths) = init(data->id_path++, room, data);
		*start = (*paths);
	}
	else
	{
		(*paths)->next = init(data->id_path++, room, data);
		(*paths)->next->prev = (*paths);
		(*paths) = (*paths)->next;
	}
	data->rooms[room].is_visit = 1;
}
