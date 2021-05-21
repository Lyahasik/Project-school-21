/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:11:19 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:11:20 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void			op_fork(t_vm *vm, t_process *proc)
{
	int			addr;
	t_process	*new;

	addr = get_op_args(vm, proc, 1, 1);
	new = proc_copy(proc, addr % IDX_MOD);
	proc_insert(&(vm->processes), new);
	vm->proc_num++;
}
