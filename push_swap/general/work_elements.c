/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:43:12 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/04 18:23:06 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*create_alement(char *value, t_element *second_element)
{
	t_element	*element;

	element = (t_element*)malloc(sizeof(t_element));
	element->number = ft_atoi(value);
	element->step_start = 0;
	element->step_destination = 0;
	element->output = 0;
	if (!second_element)
	{
		element->start = element;
		element->previous = NULL;
		element->next = NULL;
	}
	else
	{
		element->start = second_element->start;
		element->start->previous = element;
		element->next = element->start;
		second_element->next = element;
		element->previous = second_element;
	}
	return (element);
}

t_element	*search_min_element(t_element *block)
{
	t_element	*suitable_element;

	suitable_element = block;
	block = block->next;
	while (block != block->start)
	{
		if (suitable_element->number > block->number)
			suitable_element = block;
		block = block->next;
	}
	return (suitable_element);
}

void		transfer_element(int value, t_element *in_start)
{
	t_element	*new_element;

	if (in_start->next)
	{
		new_element = (t_element*)malloc(sizeof(t_element));
		new_element->number = in_start->number;
		new_element->start = in_start;
		new_element->next = in_start->next;
		new_element->previous = in_start;
		in_start->number = value;
		in_start->next->previous = new_element;
		in_start->next = new_element;
	}
	else
	{
		in_start->number = value;
		in_start->next = in_start;
		in_start->previous = in_start;
	}
}

void		delete_element(t_element *start)
{
	t_element	*deleted_element;

	if (start->next && start != start->next)
	{
		deleted_element = start->next;
		start->number = deleted_element->number;
		deleted_element->next->previous = start;
		start->next = deleted_element->next;
		free(deleted_element);
	}
	else
	{
		start->next = NULL;
		start->previous = NULL;
	}
}
