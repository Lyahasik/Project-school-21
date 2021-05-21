/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:23:57 by jsprouts          #+#    #+#             */
/*   Updated: 2020/11/15 17:44:12 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_back(t_data *data, t_paths **paths, int id, int count)
{
	int i;
	int ans;
	int prev_ind;
	int ind;
	int ans2;

	prev_ind = count == 0 ? (*paths)->path->prev->id \
						: (*paths)->path->prev->prev->id;
	ind = count == 0 ? (*paths)->path->id : (*paths)->path->prev->id;
	i = 0;
	ans = 0;
	while (i < data->rooms_amount)
	{
		if (data->connections[id][i] == -1)
		{
			ans = 1;
			break ;
		}
		i++;
	}
	ans2 = data->connections[prev_ind][ind] == -1 ? 0 : 1;
	return (ans && ans2);
}

int		no_ways(t_data *data)
{
	int i;

	i = 0;
	while (i < data->rooms_amount)
	{
		if (data->connections[data->start][i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int		to_much(t_data *data)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < data->rooms_amount)
	{
		if (data->connections[i][data->start] == -1)
			count++;
		i++;
	}
	if (data->rooms_amount > 750 && ((data->ants_num >= 400 && count >= 13) ||
		(data->ants_num <= 150 && count >= 7) ||
		(data->ants_num > 150 && data->ants_num < 200 && count >= 8) ||
		(data->ants_num >= 200 && data->ants_num < 250 && count >= 9) ||
		(data->ants_num >= 250 && data->ants_num < 300 && count >= 10) ||
		(data->ants_num >= 300 && data->ants_num < 350 && count >= 11) ||
		(data->ants_num >= 350 && data->ants_num < 400 && count >= 12)))
		return (1);
	return (0);
}

int		is_exit(t_data *data, int *count_end, t_paths *paths)
{
	int		ans;

	ans = 1;
	paths = data->start_path;
	if (data->start_path != NULL && *count_end >= 1)
	{
		ans = choose_path(data->start_path, data);
		clean_path(data, data->start_path);
		*count_end = 0;
	}
	paths = data->start_path;
	if (ans == 0 || no_ways(data) || paths == NULL || to_much(data))
	{
		if (paths != NULL && data->start_path != NULL)
			paths = data->start_path;
		while (paths != NULL)
			delete_path(&paths, data);
		return (1);
	}
	return (0);
}
