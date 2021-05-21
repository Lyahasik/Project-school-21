/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:59:16 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/14 16:59:38 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**handling_arguments(int av, char **ac)
{
	char	**arguments;
	char	*tempory;

	if (!(tempory = remove_space(av, ac)))
		return (0);
	arguments = ft_strsplit(tempory, ' ');
	free(tempory);
	if (!arguments)
		return (0);
	return (arguments);
}

char	*handling_instructions(void)
{
	char	*instructions;
	char	*tempory;
	char	*space;

	if (!(instructions = ft_strdup("")))
		return (0);
	while (get_next_line(STDIN_FILENO, &tempory))
	{
		if (ft_strlen(tempory) == 0)
		{
			free(tempory);
			break ;
		}
		if (!check_instruction(tempory))
		{
			ft_mem_free_args((void*)instructions, (void*)tempory, NULL, NULL);
			return (0);
		}
		space = ft_strjoin(" ", tempory);
		free(tempory);
		tempory = instructions;
		instructions = ft_strjoin(tempory, space);
		ft_mem_free_args((void*)space, (void*)tempory, NULL, NULL);
	}
	return (instructions);
}

int		main(int av, char **ac)
{
	t_element	*block;
	char		**arguments;
	char		*instructions;

	if (av > 1)
	{
		if (!(arguments = handling_arguments(av, ac)))
			return (ft_out_message("Error memory\n", 0));
		if (!(block = parcer(arguments, 1)) || check_duplicate(block) == 0
			|| !(instructions = handling_instructions())
			|| !(run_instructions(block, instructions)))
			return (ft_out_message("Error\n", 0) + free_block(block)
			+ ft_mem_free_two((void**)arguments));
			ft_mem_free_two((void**)arguments);
		free_block(block);
	}
	else
		output_prompt(1);
	return (0);
}
