/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:37:59 by lyahasik          #+#    #+#             */
/*   Updated: 2020/11/14 16:56:17 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instructions_s(t_element *block_a, t_element *block_b,
							char *instructions)
{
	if (!ft_strcmp(instructions, "sa"))
	{
		operation_s(block_a, NULL);
	}
	else if (!ft_strcmp(instructions, "sb"))
	{
		operation_s(NULL, block_b);
	}
	else if (!ft_strcmp(instructions, "ss"))
	{
		operation_s(block_a, block_b);
	}
}

static void	instructions_p(t_element *block_a, t_element *block_b,
							char *instructions)
{
	if (!ft_strcmp(instructions, "pa"))
	{
		operation_p(block_b, block_a);
	}
	else if (!ft_strcmp(instructions, "pb"))
	{
		operation_p(block_a, block_b);
	}
}

static void	instructions_r(t_element *block_a, t_element *block_b,
							char *instructions)
{
	if (!ft_strcmp(instructions, "ra"))
	{
		operation_r(block_a, NULL, 1);
	}
	else if (!ft_strcmp(instructions, "rb"))
	{
		operation_r(NULL, block_b, 1);
	}
	else if (!ft_strcmp(instructions, "rr"))
	{
		operation_r(block_a, block_b, 1);
	}
	else if (!ft_strcmp(instructions, "rra"))
	{
		operation_r(block_a, NULL, -1);
	}
	else if (!ft_strcmp(instructions, "rrb"))
	{
		operation_r(NULL, block_b, -1);
	}
	else if (!ft_strcmp(instructions, "rrr"))
	{
		operation_r(block_a, block_b, -1);
	}
}

t_element	*run_instructions(t_element *block_a, char *instructions)
{
	t_element	*block_b;
	char		**instructions_list;
	int			i;

	instructions_list = ft_strsplit(instructions, ' ');
	free(instructions);
	if (instructions_list == NULL)
		return (0);
	block_b = create_alement("0", NULL);
	i = -1;
	while (instructions_list[++i])
	{
		instructions_s(block_a, block_b, instructions_list[i]);
		instructions_p(block_a, block_b, instructions_list[i]);
		instructions_r(block_a, block_b, instructions_list[i]);
	}
	ft_putstr((check_sorting(block_a, block_b)) ? "OK\n" : "KO\n");
	ft_mem_free_two((void**)instructions_list);
	free_block(block_b);
	return (block_a);
}
