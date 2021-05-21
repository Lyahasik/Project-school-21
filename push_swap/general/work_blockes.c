/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_blockes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:43:12 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/14 16:32:49 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_max(t_element *block)
{
	int	max;

	max = INT_MIN;
	block = block->start;
	if (block->number > max)
		max = block->number;
	block = block->next;
	while (block != block->start)
	{
		if (block->number > max)
			max = block->number;
		block = block->next;
	}
	return (max);
}

int			find_min(t_element *block)
{
	int	min;

	min = INT_MAX;
	block = block->start;
	if (block->number < min)
		min = block->number;
	block = block->next;
	while (block != block->start)
	{
		if (block->number < min)
			min = block->number;
		block = block->next;
	}
	return (min);
}

int			free_block(t_element *block)
{
	t_element	*delete_element;

	if (!block)
		return (0);
	block = block->start;
	while (block->next && block->next != block->start)
	{
		delete_element = block;
		block = block->next;
		free(delete_element);
	}
	free(block);
	return (0);
}

/*
** Перевод всех аргументов в список чисел для основного алгоритма.
** input_1 массив строк с подаными аргументами.
** input_2 (0) вызов из push_swap, (1) вызов из checker.
** return готовый список, либо NULL.
*/

t_element	*parcer(char **arguments, int checker)
{
	t_element	*block;
	int			output;
	int			i;

	block = NULL;
	i = -1;
	while (arguments[++i])
	{
		if (checker == 0 && i == 0)
		{
			if ((output = check_argument(arguments[i])) == -1)
				return (0);
			if (output > 0)
				continue ;
		}
		if (check_argument(arguments[i]) != 0)
			return (free_block(block) == 0 ? NULL : NULL);
		if (arguments[i])
			block = create_alement(arguments[i], block);
	}
	if (block)
		block->start->output = output;
	return (block ? block->start : NULL);
}

int			count_elements(t_element *block)
{
	int number;

	number = 0;
	if (block->next)
		number++;
	block = block->next;
	while (block && block != block->start)
	{
		number++;
		block = block->next;
	}
	return (number);
}
