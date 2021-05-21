/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_preparation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:05:04 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:05:47 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

static void	numerate_players(t_vm *vm, int *index)
{
	int i;
	int j;

	i = -1;
	while (++i < N_PLAYERS)
	{
		if (PLAYER[i].n_num)
			continue;
		j = -1;
		while (++j < N_PLAYERS && index[j])
			;
		PLAYER[i].n_num = j + 1;
		index[j]++;
	}
}

static void	prep_players(t_vm *vm)
{
	int *index;
	int i;

	i = -1;
	index = ft_memalloc(N_PLAYERS * 4);
	while (++i < N_PLAYERS)
	{
		PLAYER[i].id_op = 2;
		if (PLAYER[i].n_on && PLAYER[i].n_num > 0 &&
			PLAYER[i].n_num <= N_PLAYERS &&
			index[PLAYER[i].n_num - 1] == 0)
			index[PLAYER[i].n_num - 1]++;
		else
			PLAYER[i].n_num = 0;
	}
	numerate_players(vm, index);
	sort_players(vm);
	free(index);
}

static void	prep_stage(t_vm *vm)
{
	int delta;
	int i;

	delta = MEM_SIZE / N_PLAYERS;
	i = -1;
	while (++i < N_PLAYERS)
		ft_memcpy(STAGE + delta * i,
				PLAYER[i].exec_code, PLAYER[i].exec_size);
}

static void	prep_proc(t_vm *vm)
{
	int i;
	int addr;

	i = -1;
	addr = 0;
	while (++i < N_PLAYERS)
	{
		proc_insert(&(vm->processes), proc_init(i + 1, addr));
		vm->proc_num++;
		addr += MEM_SIZE / N_PLAYERS;
	}
}

void		vm_prep(t_vm *vm)
{
	prep_players(vm);
	prep_stage(vm);
	prep_proc(vm);
	prep_presentation(vm);
	vm->survivor_id = N_PLAYERS;
}
