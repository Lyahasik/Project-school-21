/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displacement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:43:12 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/14 16:28:39 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Переносит все в стек b
** @let количество сдвигов каретки
*/

void	push_b(t_element *block_a, t_element *block_b, int let)
{
	while (let-- > 0)
	{
		if (block_a && block_a->next != block_a->start)
			block_a = block_a->next;
		else
			return ;
	}
	while (block_a != block_a->start)
	{
		operation_p(block_a, block_b);
		ft_printf("pb\n");
		output_blocks(block_a->start, block_b);
		block_a = block_a->next;
	}
}

void	put_in_place(t_element *block_a, t_element *block_b)
{
	t_element	*block;

	block = min_way(block_a, block_b);
	if (block->step_start != 0)
	{
		rotate_drum(block_b, block_a, block->step_start, 'b');
	}
	if (block->step_destination != 0)
	{
		rotate_drum(block_a, block_b, block->step_destination, 'a');
	}
	operation_p(block_b, block_a);
	ft_printf("pa\n");
	output_blocks(block_a, block_b);
}
