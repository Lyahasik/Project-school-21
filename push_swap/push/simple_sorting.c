/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:43:12 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/14 03:15:36 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_less(t_element *block_a, t_element *block_b)
{
	if (block_a->next->number > block_a->next->next->number
		&& block_a->next->next->number > block_a->number)
	{
		operation_r(block_a, NULL, -1);
		ft_printf("rra\n");
		output_blocks(block_a, block_b);
		operation_s(block_a, NULL);
		ft_printf("sa\n");
	}
	else if (block_a->number > block_a->next->next->number)
	{
		operation_r(block_a, NULL, -1);
		ft_printf("rra\n");
	}
}

static void	first_more(t_element *block_a, t_element *block_b)
{
	if (block_a->next->number < block_a->next->next->number
		&& block_a->next->next->number > block_a->number)
	{
		operation_s(block_a, NULL);
		ft_printf("sa\n");
	}
	else if (block_a->next->number < block_a->next->next->number
		&& block_a->next->next->number < block_a->number)
	{
		operation_r(block_a, NULL, 1);
		ft_printf("ra\n");
	}
	else
	{
		operation_s(block_a, NULL);
		ft_printf("sa\n");
		output_blocks(block_a, block_b);
		operation_r(block_a, NULL, -1);
		ft_printf("rra\n");
	}
}

void		sorting_three(t_element *block_a, t_element *block_b)
{
	if (block_a->number < block_a->next->number)
	{
		first_less(block_a, block_b);
		output_blocks(block_a, block_b);
	}
	else if (block_a->number > block_a->next->number)
	{
		first_more(block_a, block_b);
		output_blocks(block_a, block_b);
	}
}

void		start_simple_sorting(t_element *block_a, t_element *block_b)
{
	t_element	*min_element;
	int			step_up;
	int			step_down;

	while (block_b->next)
	{
		put_in_place(block_a, block_b);
	}
	min_element = search_min_element(block_a);
	step_up = check_steps(min_element, min_element->start, 1);
	step_down = check_steps(min_element, min_element->start, -1);
	rotate_drum(block_a, block_b, (step_up < -step_down)
		? step_up : step_down, 'a');
}
