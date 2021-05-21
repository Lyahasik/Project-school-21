/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:24:04 by lyahasik          #+#    #+#             */
/*   Updated: 2020/11/14 16:37:22 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_element	*output_block(t_element *block_a, t_element *block_b,
								int *count)
{
	if (block_a)
	{
		ft_printf("%11d| |", block_a->number);
		block_a = block_a->next;
	}
	else
	{
		ft_printf("%-11d\n", block_b->number);
		block_b = block_b->next;
	}
	(*count)--;
	return (block_a ? block_a : block_b);
}

static void			output_line(t_element *block_a, t_element *block_b,
			int number_left, int number_right)
{
	while (number_left > 0 || number_right > 0)
	{
		if (number_left == number_right)
		{
			block_a = output_block(block_a, NULL, &number_left);
			block_b = output_block(NULL, block_b, &number_right);
		}
		else if (number_left > number_right)
		{
			block_a = output_block(block_a, NULL, &number_left);
			ft_printf("%-11c\n", ' ');
		}
		else
		{
			ft_printf("%11c| |", ' ');
			block_b = output_block(NULL, block_b, &number_right);
		}
	}
}

void				output_blocks(t_element *block_a, t_element *block_b)
{
	int	number_left;
	int	number_right;

	if (block_a->output != 0)
	{
		number_left = count_elements(block_a);
		number_right = count_elements(block_b);
		if (number_left == 0 && !block_a->next)
			ft_printf("%11d| |%-11c\n", block_a->number, ' ');
		output_line(block_a, block_b, number_left, number_right);
		ft_printf("-------------------------\n");
	}
}

void				output_prompt(int checker)
{
	ft_putstr("Введите числовые аргументы.\n");
	if (checker == 0)
	{
		ft_putstr("Первым аргументом может быть флаг отображения:\n");
		ft_putstr(" -v - вывод шагов в консоль\n");
	}
}
