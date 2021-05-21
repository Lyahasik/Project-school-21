/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:37:25 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/05 23:37:28 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/corewar.h"

void		get_op_code(t_vm *vm, t_process *proc)
{
	int		code_id;

	code_id = get_byte_int(vm, PROC_POS, OP_CODE_LEN);
	proc->id_op = code_id;
	if (code_id >= 1 && code_id <= OP_N_FUN)
		proc->cycle_op = g_op[code_id - 1].cycles;
}

void		get_op_type_agrs(t_vm *vm, t_process *proc, t_op *op)
{
	int		type_args;

	if (op->is_type_args)
	{
		type_args = get_byte_int(vm, PROC_POS + OP_CODE_LEN, ARGS_CODE_LEN);
		if (op->args_num >= 1)
			proc->type_args[0] = g_type_args[((type_args & MASK_R) >> 6) - 1];
		if (op->args_num >= 2)
			proc->type_args[1] = g_type_args[((type_args & MASK_G) >> 4) - 1];
		if (op->args_num >= 3)
			proc->type_args[2] = g_type_args[((type_args & MASK_B) >> 2) - 1];
		return ;
	}
	proc->type_args[0] = op->type_args[0];
}

int			gap_op_args(t_process *proc, t_op *op)
{
	int		step;
	int		i;

	i = -1;
	step = OP_CODE_LEN + (op->is_type_args ? ARGS_CODE_LEN : 0);
	while (++i < op->args_num)
		step += get_step(proc->type_args[i], op);
	return (step);
}

int			get_op_args(t_vm *vm, t_process *proc, int index_arg, int is_mod)
{
	t_op	*op;
	int32_t	value;
	int		addr;

	op = &g_op[proc->id_op - 1];
	value = 0;
	if (PROC_TA[index_arg - 1] & T_REG)
		value = PROC_REG[get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN) - 1];
	else if (PROC_TA[index_arg - 1] & T_DIR)
		value = get_byte_int(vm, PROC_POS + PROC_STEP, op->t_dir_size);
	else if (PROC_TA[index_arg - 1] & T_IND)
	{
		addr = get_byte_int(vm, PROC_POS + PROC_STEP, IND_SIZE);
		addr = is_mod ? (addr % IDX_MOD) : addr;
		value = get_byte_int(vm, PROC_POS + addr, DIR_SIZE);
	}
	PROC_STEP += get_step(PROC_TA[index_arg - 1], op);
	return (value);
}
