/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:43:12 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/14 16:32:18 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*min_total(t_element *block)
{
	t_element	*block_min;

	block_min = block;
	block = block->next;
	while (block != block->start)
	{
		if (block_min->step_total > block->step_total)
			block_min = block;
		block = block->next;
	}
	return (block_min);
}

t_element	*min_way(t_element *block_a, t_element *block_b)
{
	recount_steps(block_b, block_a);
	block_b = block_b->next;
	while (block_b != block_b->start)
	{
		recount_steps(block_b, block_a);
		block_b = block_b->next;
	}
	return (min_total(block_b));
}

void		recount_steps(t_element *to_block, t_element *in_block)
{
	int	step_up;
	int	step_down;

	step_up = check_steps(to_block, to_block->start, 1);
	step_down = check_steps(to_block, to_block->start, -1);
	to_block->step_start = (step_up < -step_down) ? step_up : step_down;
	step_up = check_steps(in_block,
		search_position(to_block->number, in_block), 1);
	step_down = check_steps(in_block,
		search_position(to_block->number, in_block), -1);
	to_block->step_destination = (step_up < -step_down)
		? -step_up : -step_down;
	to_block->step_total =
		ft_abs(to_block->step_start) + ft_abs(to_block->step_destination);
}

/*
** Подсчет поворотов для перемещения элемента на позицию in_block
** @rhezus в каком направлении считать вверх/низ
*/

int			check_steps(t_element *to_block, t_element *in_block, int rhesus)
{
	int	count;

	count = 0;
	if (rhesus > 0)
	{
		while (to_block != in_block)
		{
			to_block = to_block->previous;
			count++;
		}
	}
	else
	{
		while (to_block != in_block)
		{
			to_block = to_block->next;
			count--;
		}
	}
	return (count);
}

t_element	*search_position(int value, t_element *block)
{
	int	min;
	int	max;

	min = find_min(block);
	max = find_max(block);
	block = block->start->next;
	while (block != block->start)
	{
		if ((value < min && block->number == min)
			|| (value < block->number && value > block->previous->number))
			return (block);
		if (value > max && block->number == max)
			return (block->next);
		block = block->next;
	}
	if ((value < min && block->number == min)
		|| (value < block->number && value > block->previous->number))
		return (block);
	if (value > max && block->number == max)
		return (block->next);
	return (block->start);
}
