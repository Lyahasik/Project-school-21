/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:12:48 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:13:55 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_zjmp(t_vm *vm, t_process *proc)
{
	int		addr;

	addr = get_op_args(vm, proc, 1, 1);
	if (proc->carry)
	{
		PROC_POS = mod_position(PROC_POS + (addr % IDX_MOD));
		PROC_STEP = 0;
	}
}
