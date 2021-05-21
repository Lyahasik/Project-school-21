/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:23:46 by jsprouts          #+#    #+#             */
/*   Updated: 2020/11/15 17:44:12 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_path(t_paths **paths, t_data *data)
{
	t_cont	*to_clean;
	t_paths	*to_cln_pth;

	to_clean = (*paths)->start;
	to_cln_pth = *paths;
	while ((*paths)->start != NULL)
	{
		(*paths)->start = (*paths)->start->next;
		free(to_clean);
		to_clean = (*paths)->start;
	}
	if ((*paths)->prev != NULL)
		*paths = (*paths)->prev;
	else if ((*paths)->next != NULL)
	{
		*paths = (*paths)->next;
		data->is_first = 1;
	}
	else
		*paths = NULL;
	free(to_cln_pth);
}

void	only_one_path(t_paths **paths, t_data *data)
{
	t_cont	*to_clean;

	to_clean = (*paths)->start;
	data->start_path = NULL;
	data->last_path = NULL;
	while ((*paths)->start != NULL)
	{
		(*paths)->start = (*paths)->start->next;
		free(to_clean);
		to_clean = (*paths)->start;
	}
	free(*paths);
	*paths = NULL;
}

void	delete_path(t_paths **paths, t_data *data)
{
	if (*paths == NULL)
		return ;
	if ((*paths)->prev && (*paths)->next)
	{
		(*paths)->prev->next = (*paths)->next;
		(*paths)->next->prev = (*paths)->prev;
	}
	else if ((*paths)->prev == NULL && (*paths)->next == NULL)
	{
		only_one_path(paths, data);
		return ;
	}
	else if ((*paths)->prev == NULL)
	{
		(*paths)->next->prev = NULL;
		data->start_path = (*paths)->next;
	}
	else if ((*paths)->next == NULL)
	{
		(*paths)->prev->next = NULL;
		data->last_path = (*paths)->prev;
	}
	free_path(paths, data);
}

void	to_zero_id_path(t_data *data)
{
	int i;

	i = 0;
	while (i != data->rooms_amount)
	{
		if (data->connections[data->start][i] == 0)
		{
			data->rooms[i].is_visit = 0;
			data->rooms[i].id_path = -1;
		}
		i++;
	}
}

void	clean_path(t_data *data, t_paths *paths)
{
	paths = data->start_path;
	while (paths != NULL)
	{
		delete_path(&paths, data);
	}
	data->start_path = NULL;
	data->last_path = NULL;
	paths = NULL;
	to_zero_id_path(data);
	bfs_shortest_path(data);
}
