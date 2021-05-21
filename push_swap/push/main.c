/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:43:12 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/26 20:34:33 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			simple_algorithm(t_element *block_a)
{
	t_element	*block_b;

	block_b = create_alement("0", NULL);
	if (!check_sorting(block_a, block_b))
	{
		if (block_a == block_a->next->next
			&& block_a->number > block_a->next->number)
		{
			operation_s(block_a, NULL);
			ft_printf("sa\n");
			output_blocks(block_a, block_b);
			return (free_block(block_b));
		}
		if (block_a == block_a->next->next->next)
		{
			sorting_three(block_a, block_b);
			return (free_block(block_b));
		}
		push_b(block_a, block_b, 3);
		sorting_three(block_a, block_b);
		start_simple_sorting(block_a, block_b);
	}
	else
		output_blocks(block_a, block_b);
	return (free_block(block_b));
}

int			main(int av, char **ac)
{
	t_element	*block;
	char		**arguments;
	char		*arguments_line;

	if (av > 1)
	{
		arguments_line = remove_space(av, ac);
		arguments = ft_strsplit(arguments_line, ' ');
		free(arguments_line);
		if (!arguments)
			return (ft_out_message("Error: memory\n", 0));
		if (!(block = parcer(arguments, 0)) || check_duplicate(block) == 0)
			return (ft_out_message("Error\n", 0) + free_block(block)
			+ ft_mem_free_two((void**)arguments));
			simple_algorithm(block);
		ft_mem_free_two((void**)arguments);
		free_block(block);
	}
	else
	{
		output_prompt(0);
	}
	return (0);
}
