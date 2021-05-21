/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:11:45 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:13:17 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void			op_live(t_vm *vm, t_process *proc)
{
	int			player_id;
	t_player	*player;

	player = NULL;
	player_id = get_op_args(vm, proc, 1, 0);
	proc->cycle_live = vm->n_loop;
	vm->count_live++;
	if (player_id < 0 && player_id >= -(vm->players_num))
	{
		player = &vm->players[-player_id - 1];
		player->loop_live = vm->n_loop;
		vm->survivor_id = -player_id;
	}
}
