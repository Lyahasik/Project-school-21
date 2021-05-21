/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_war.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:42:23 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/05 23:45:53 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/corewar.h"
#include "../../header/graphic.h"

void	vm_exec_op(t_vm *vm, t_process *proc, t_op *op)
{
	if (op)
	{
		get_op_type_agrs(vm, proc, op);
		if (vm_valid_args(vm, proc, op))
		{
			vm->players[proc->id_player - 1].id_op = proc->id_op;
			PROC_STEP += OP_CODE_LEN;
			op->func(vm, proc);
		}
		else
			PROC_STEP += gap_op_args(proc, op);
	}
	else
		PROC_STEP = OP_CODE_LEN;
	proc_step(proc);
}

void	vm_run_op(t_vm *vm, t_process *proc)
{
	t_op *op;

	op = NULL;
	if (proc->cycle_op == 0)
		get_op_code(vm, proc);
	if (proc->cycle_op > 0)
		proc->cycle_op--;
	if (proc->cycle_op == 0)
	{
		if (proc->id_op >= 1 && proc->id_op <= OP_N_FUN)
			op = &g_op[proc->id_op - 1];
		vm_exec_op(vm, proc, op);
		if (vm->visualizer)
			vm->graphic->field->carriage_pos = PROC_POS;
	}
}

void	vm_loop_war(t_vm *vm)
{
	t_process *cur_proc;

	vm->n_loop += 1;
	vm->n_loop_check += 1;
	cur_proc = PROC;
	while (cur_proc)
	{
		vm_run_op(vm, cur_proc);
		cur_proc = cur_proc->next;
	}
}

void	vm_war(t_vm *vm)
{
	while (vm->proc_num)
	{
		if (DUMP != -1 && vm->n_loop == DUMP)
			return ;
		vm_loop_war(vm);
		if (vm->n_loop_check == vm->n_loop_dead || vm->n_loop_dead <= 0)
			vm_proc_dead(vm);
	}
}
