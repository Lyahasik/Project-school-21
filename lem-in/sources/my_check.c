/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:14:54 by jsprouts          #+#    #+#             */
/*   Updated: 2020/11/15 17:44:12 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		compare_and_delete_path(t_paths **elem, t_data *data, int diff)
{
	if (diff < 0)
		return (1);
	else
	{
		delete_path(elem, data);
		return (0);
	}
}

int		check_links_and_del_path(t_paths **paths, t_paths **elem, t_data *data)
{
	int id_1;
	int id_2;
	int count;
	int i;

	count = 0;
	id_1 = (*paths)->path->id;
	id_2 = (*elem)->path->prev->id;
	i = -1;
	while (++i != data->rooms_amount)
		if (data->connections[id_1][i] != 0)
			count++;
	i = -1;
	while (++i != data->rooms_amount)
		if (data->connections[id_2][i] != 0)
			count--;
	if (count > 0)
		return (1);
	delete_path(elem, data);
	return (0);
}

int		check_size(t_paths *elem, int room)
{
	int		true_size;
	t_cont	*path;

	true_size = 0;
	path = elem->start;
	while (path->id != room)
	{
		path = path->next;
		true_size++;
	}
	return (true_size);
}

int		is_better(t_data *data, t_paths **paths, int room, int from)
{
	t_paths	*elem;
	int		i;

	i = 0;
	elem = data->start_path;
	while (elem->id_path != data->rooms[room].id_path)
	{
		elem = elem->next;
		if (elem == NULL)
			return (0);
		i++;
	}
	if (check_size(elem, room) != check_size(*paths, from) + 1)
		return (compare_and_delete_path(&elem, data, check_size(elem, room) \
			- (check_size(*paths, from) + 1)));
	else
		return (check_links_and_del_path(paths, &elem, data));
}

int		choose_path(t_paths *paths, t_data *data)
{
	t_cont *to_cln;

	while (paths->path->id != data->end)
	{
		paths = paths->next;
		if (paths == NULL)
			return (0);
	}
	paths->path = paths->start;
	while (paths->path->next != NULL)
	{
		if (data->connections[paths->path->id][paths->path->next->id] != -1)
			data->connections[paths->path->next->id][paths->path->id] = -1;
		data->connections[paths->path->id][paths->path->next->id] = 0;
		paths->path = paths->path->next;
	}
	to_cln = paths->path->next;
	while (to_cln != NULL)
	{
		data->rooms[to_cln->id].is_visit = 0;
		data->rooms[to_cln->id].id_path = -1;
		to_cln = to_cln->next;
	}
	delete_path(&paths, data);
	return (1);
}
