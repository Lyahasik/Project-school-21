/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_step.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakarov <smakarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:25:18 by jsprouts          #+#    #+#             */
/*   Updated: 2020/12/05 12:03:20 by smakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_one_step(t_data *data, t_room room, t_paths *paths)
{
	int		num;
	int		i;

	num = data->ants_num;
	i = 1;
	if (data->connections[data->start][data->end])
	{
		while (paths != NULL)
			delete_path(&paths, data);
		print_line(data->input);
		while (num != 0)
		{
			out_one_step(i, room.name);
			i++;
			num--;
		}
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

void			step_in_paths(t_data *data)
{
	int		count_end;
	t_paths	*paths;
	int		id_path;

	bfs_shortest_path(data);
	paths = data->start_path;
	if (no_ways(data) || paths == NULL ||\
		check_one_step(data, data->rooms[data->end], data->start_path))
		return ;
	count_end = 0;
	while (count_end == 0)
	{
		id_path = data->last_path->id_path;
		while (paths != NULL && paths->id_path <= id_path)
		{
			data->is_first = 0;
			next_room(data, &paths, &count_end);
			if (paths != NULL && (data->is_first != 1 ||
				paths->path->id == data->end))
				paths = paths->next;
		}
		if (is_exit(data, &count_end, paths))
			break ;
		paths = data->start_path;
	}
}

void			bfs_shortest_path(t_data *data)
{
	int		i;
	t_paths	*paths;

	paths = NULL;
	i = 0;
	data->id_path = 0;
	while (i != data->rooms_amount)
	{
		if (data->connections[data->start][i] == 1)
			create_path(data, &paths, i, &(data->start_path));
		i++;
	}
	data->last_path = paths;
}

int				conditions(t_data *data, t_elem *elem,\
							t_paths **paths, int *count_end)
{
	if (elem->i == data->start || (is_back(data, paths, elem->id, \
		elem->count) && data->connections[elem->id][elem->i] != -1))
	{
		elem->i++;
		return (1);
	}
	if (data->rooms[elem->i].is_visit == 1)
		elem->isbet = is_better(data, paths, elem->i, elem->id);
	if ((*paths)->start == NULL)
	{
		*paths = NULL;
		elem->isbet = 1;
		return (0);
	}
	data->rooms[elem->i].is_visit = 1;
	if (elem->count == 0 && elem->isbet != 1)
	{
		add_room(data, *paths, elem->i, count_end);
		elem->count++;
	}
	else if (elem->count > 0 && elem->isbet != 1)
		create_new_path(data, *paths, elem->i, count_end);
	return (2);
}

void			next_room(t_data *data, t_paths **paths, int *count_end)
{
	t_elem	elem;
	int		check;

	elem.i = 0;
	elem.count = 0;
	elem.id = (*paths)->path->id;
	elem.id_prev = (*paths)->path->prev->id;
	while (elem.i != data->rooms_amount)
	{
		elem.isbet = 0;
		if (data->connections[elem.id][elem.i] != 0 && elem.i != elem.id_prev)
		{
			check = conditions(data, &elem, paths, count_end);
			if (check == 1)
				continue ;
			else if (check == 0)
				break ;
		}
		elem.i++;
	}
	if (elem.count == 0)
		delete_path(paths, data);
}
