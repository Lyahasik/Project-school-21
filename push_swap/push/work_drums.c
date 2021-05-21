/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_drums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:43:12 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/14 01:10:53 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Поворачивать барабан вверх пока quantity != 0
*/

static void	rotate_drum_up(t_element *rotatable_block,
			t_element *second_block, int quantity, char block_name)
{
	while (quantity > 0)
	{
		operation_r(rotatable_block, NULL, 1);
		ft_printf("r%c\n", block_name);
		if (block_name == 'a')
			output_blocks(rotatable_block, second_block);
		else
			output_blocks(second_block, rotatable_block);
		quantity--;
	}
}

/*
** Поворачивать барабан вниз пока quantity != 0
*/

static void	rotate_drum_down(t_element *rotatable_block,
			t_element *second_block, int quantity, char block_name)
{
	while (quantity < 0)
	{
		operation_r(rotatable_block, NULL, -1);
		ft_printf("rr%c\n", block_name);
		if (block_name == 'a')
			output_blocks(rotatable_block, second_block);
		else
			output_blocks(second_block, rotatable_block);
		quantity++;
	}
}

void		rotate_drum(t_element *rotatable_block,
		t_element *second_block, int quantity, char block_name)
{
	if (quantity > 0)
	{
		rotate_drum_up(rotatable_block, second_block, quantity, block_name);
	}
	else
	{
		rotate_drum_down(rotatable_block, second_block, quantity, block_name);
	}
}
