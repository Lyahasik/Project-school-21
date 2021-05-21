/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_preparation_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:06:03 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:06:06 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void	sort_players(t_vm *vm)
{
	int			i;
	int			j;
	t_player	tmp;

	i = -1;
	while (++i < N_PLAYERS)
	{
		j = i;
		while (++j < N_PLAYERS)
		{
			if (PLAYER[i].n_num > PLAYER[j].n_num)
			{
				tmp = PLAYER[i];
				PLAYER[i] = PLAYER[j];
				PLAYER[j] = tmp;
			}
		}
	}
}

void	prep_presentation(t_vm *vm)
{
	int i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (++i <= N_PLAYERS)
	{
		ft_printf("Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			PLAYER[i - 1].n_num, PLAYER[i - 1].exec_size,
				PLAYER[i - 1].name, PLAYER[i - 1].comment);
	}
}
