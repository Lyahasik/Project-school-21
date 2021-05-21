/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:43:12 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/04 18:20:23 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operation_sx(t_element *block)
{
	if (block->next && block != block->next)
	{
		block = block->start;
		ft_swap(&block->number, &block->next->number);
	}
}

void		operation_s(t_element *block_a, t_element *block_b)
{
	if (block_a && block_b)
	{
		operation_sx(block_a);
		operation_sx(block_b);
	}
	else if (block_a)
	{
		operation_sx(block_a);
	}
	else
	{
		operation_sx(block_b);
	}
}

void		operation_p(t_element *to_block, t_element *in_block)
{
	if (to_block->next)
	{
		transfer_element(to_block->start->number, in_block->start);
		delete_element(to_block->start);
	}
}

static void	operation_rx(t_element *block, int rhesus)
{
	int	temp;

	if (!block->next)
		return ;
	temp = block->number;
	if (rhesus > 0)
	{
		block->number = block->next->number;
		while (block->next != block->start)
		{
			block = block->next;
			block->number = block->next->number;
		}
		block->number = temp;
	}
	else
	{
		block->number = block->previous->number;
		while (block->previous != block->start)
		{
			block = block->previous;
			block->number = block->previous->number;
		}
		block->number = temp;
	}
}

void		operation_r(t_element *block_a, t_element *block_b, int rhesus)
{
	if (block_a && block_b)
	{
		operation_rx(block_a, rhesus);
		operation_rx(block_b, rhesus);
	}
	else if (block_a)
	{
		operation_rx(block_a, rhesus);
	}
	else
	{
		operation_rx(block_b, rhesus);
	}
}
