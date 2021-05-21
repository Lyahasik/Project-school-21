/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_init_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:24:40 by jsprouts          #+#    #+#             */
/*   Updated: 2020/11/15 17:44:12 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_path(t_data data, t_path **ret, t_cont **path, int i)
{
	int k;

	k = 0;
	while (k < data.rooms_amount)
		data.rooms[k++].is_visit = 0;
	data.rooms[data.start].is_visit = 1;
	data.rooms[i].is_visit = 1;
	*ret = (t_path*)ft_palloc(sizeof(t_path));
	*path = (t_cont*)ft_palloc(sizeof(t_cont));
	(*ret)->size = 0;
	(*path)->id = i;
	(*path)->ant = 0;
	(*path)->next = NULL;
	(*ret)->next = NULL;
	(*path)->prev = NULL;
	(*ret)->path = (*path);
	(*ret)->first = (*path);
}

void	init_node_links(t_cont **path, int k)
{
	(*path)->next = (t_cont*)ft_palloc(sizeof(t_cont));
	(*path)->next->id = k;
	(*path)->next->ant = 0;
	(*path)->next->next = NULL;
	(*path)->next->prev = (*path);
	(*path) = (*path)->next;
}

void	*ft_palloc(size_t i)
{
	void	*arg;

	if (!(arg = (void*)malloc(i)))
	{
		write(1, "\033[31mError\033[0m\n", 15);
		exit(-1);
	}
	return (arg);
}
