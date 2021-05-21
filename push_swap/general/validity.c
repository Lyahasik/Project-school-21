/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:43:12 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/14 17:10:36 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Проверка аргумента.
** input_1 строка с аргументом.
** return (-1) - неверный аргумент, (n >= 0) - обрабатываемые аргументы.
*/

int		check_argument(char *argument)
{
	if (!ft_strcmp(argument, "-v"))
		return (1);
	if (!ft_check_atoi_int(argument))
		return (-1);
	return (0);
}

/*
** Проверка аргументов на дубликаты.
** input_1 структура данных ячейки.
** return (0) - есть, (1) - нет.
*/

int		check_duplicate(t_element *block)
{
	t_element	*temporary;

	if (block->next)
	{
		temporary = block;
		block = block->next;
		while (temporary->next != block->start)
		{
			if (temporary->number == block->number)
			{
				return (0);
			}
			else
			{
				block = block->next;
				if (block == temporary)
				{
					temporary = temporary->next;
					block = temporary->next;
				}
			}
		}
	}
	return (1);
}

/*
** Проверка инструкции.
** input_1 строка с инструкцией.
** return (0) - неверная инструкция, (1) - существующая инструкция.
*/

int		check_instruction(char *instruction)
{
	char	**base;
	int		i;

	if (!(base = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ')))
		return (0);
	i = -1;
	while (base[++i])
	{
		if (ft_strcmp(base[i], instruction) == 0)
		{
			ft_mem_free_two((void**)base);
			return (1);
		}
	}
	return (ft_mem_free_two((void**)base));
}

int		check_sorting(t_element *block_a, t_element *block_b)
{
	if (block_b->next)
	{
		return (0);
	}
	if (block_a->next && block_a != block_a->next)
	{
		while (block_a->next != block_a->start)
		{
			if (block_a->number > block_a->next->number)
			{
				return (0);
			}
			block_a = block_a->next;
		}
	}
	return (1);
}

/*
** Объединение всех аргументов в одну строку.
** input_1 количество поданных аргументов.
** input_2 массив строк с подаными аргументами.
** return строка содержащая все аргументы.
*/

char	*remove_space(int av, char **ac)
{
	char	*tempory;
	char	*space;
	char	*arguments;
	int		i;

	i = 0;
	while (++i < av)
	{
		if (!(tempory = (i == 1) ? ft_strdup("") : arguments))
			return (0);
		space = ft_strjoin(" ", ac[i]);
		arguments = ft_strjoin(tempory, space);
		free(tempory);
		free(space);
		if (!arguments)
			return (0);
	}
	return (arguments);
}
