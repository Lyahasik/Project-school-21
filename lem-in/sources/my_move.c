/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:24:52 by jsprouts          #+#    #+#             */
/*   Updated: 2020/11/15 17:44:12 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	run_ant(t_data data, int *ant, int *finished)
{
	if (*ant <= data.ants_num)
	{
		while (data.paths != NULL)
		{
			if ((data.paths->first->ant == 0 &&
				data.paths->ratio < data.ants_num - (*ant) + 1)
				|| data.paths->first == data.paths->last)
			{
				print_ant_step(ft_itoa(*ant), \
					data.rooms[data.paths->first->id].name);
				if (data.paths->first == data.paths->last)
					if (++(*finished) >= data.ants_num)
						return ;
				data.paths->first->ant = *ant;
				if (++(*ant) > data.ants_num)
					break ;
			}
			data.paths = data.paths->next;
		}
	}
	write(1, "\n", 1);
}

void	move_ant(t_data *data, t_cont *curr, t_path *c_path)
{
	if (curr->ant != 0)
	{
		if (curr->next == c_path->last)
		{
			print_ant_step(ft_itoa(curr->ant), \
				data->rooms[curr->next->id].name);
			if (++(data->finished) >= data->ants_num)
				return ;
		}
		else
		{
			print_ant_step(ft_itoa(curr->ant), \
				data->rooms[curr->next->id].name);
			curr->next->ant = curr->ant;
		}
		curr->ant = 0;
	}
}

void	move_possible(t_data *data)
{
	t_path *c_path;
	t_cont *curr;

	c_path = data->paths;
	curr = c_path->last;
	while (c_path != NULL)
	{
		curr = c_path->last->prev;
		while (curr != NULL)
		{
			move_ant(data, curr, c_path);
			curr = curr->prev;
		}
		c_path = c_path->next;
	}
}

void	count_ratio(t_data data)
{
	int i;
	int sum;

	i = 1;
	sum = data.paths->size;
	data.paths->ratio = 0;
	data.paths = data.paths->next;
	while (data.paths != NULL)
	{
		data.paths->ratio = i * data.paths->size - sum;
		sum += data.paths->size;
		i++;
		data.paths = data.paths->next;
	}
}

void	move_ants(t_data data)
{
	int ant;

	ant = 1;
	data.finished = 0;
	count_ratio(data);
	while (data.finished < data.ants_num)
	{
		run_ant(data, &ant, &(data.finished));
		move_possible(&data);
	}
	write(1, "\n", 1);
}
