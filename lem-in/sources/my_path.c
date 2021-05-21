/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:25:10 by jsprouts          #+#    #+#             */
/*   Updated: 2020/11/15 17:44:12 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*form_path(int i, t_data data)
{
	t_path	*ret;
	t_cont	*path;
	int		k;

	init_path(data, &ret, &path, i);
	while (path->id != data.end)
	{
		k = 0;
		while (1)
		{
			if (data.connections[k][i] == -1 && data.rooms[k].is_visit == 0)
			{
				init_node_links(&path, k);
				ret->size++;
				data.rooms[k].is_visit = 1;
				i = k;
				break ;
			}
			k++;
		}
	}
	ret->last = path;
	return (ret);
}

void	find_pos(t_path *ret, t_path *cur)
{
	t_path	*buf;
	t_path	*tmp;

	buf = ret;
	while (buf != NULL)
	{
		if (cur->size >= buf->size && cur->size <= buf->next->size)
		{
			tmp = buf->next;
			buf->next = cur;
			cur->next = tmp;
			break ;
		}
		buf = buf->next;
	}
}

void	first_three_paths(t_path **last, t_path **ret, t_path *cur)
{
	if (*ret == NULL)
	{
		*ret = cur;
		*last = cur;
	}
	else if (cur->size <= (*ret)->size)
	{
		cur->next = *ret;
		*ret = cur;
	}
	else if (cur->size >= (*last)->size)
	{
		(*last)->next = cur;
		*last = (*last)->next;
	}
}

t_path	*get_paths(t_data data)
{
	t_path	*last;
	t_path	*ret;
	t_path	*cur;
	int		i;

	ret = NULL;
	last = NULL;
	i = 0;
	while (i < data.rooms_amount)
		data.rooms[i++].is_visit = 0;
	i = 0;
	while (i < data.rooms_amount)
	{
		if (data.connections[i][data.start] == -1)
		{
			cur = form_path(i, data);
			if (ret == NULL || cur->size <= ret->size ||
				cur->size >= last->size)
				first_three_paths(&last, &ret, cur);
			else
				find_pos(ret, cur);
		}
		i++;
	}
	return (ret);
}
