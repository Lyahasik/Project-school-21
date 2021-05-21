/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:41:39 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/05 23:41:42 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/corewar.h"

int			valid_type_args(t_process *proc, t_op *op)
{
	int		i;

	i = -1;
	while (++i < op->args_num)
		if (!(proc->type_args[i] & op->type_args[i]))
			return (0);
	return (1);
}

int			valid_reg_args(t_vm *vm, t_process *proc, int step)
{
	int		value;

	value = get_byte_int(vm, PROC_POS + step, T_REG);
	return (value > 0 && value <= REG_NUMBER);
}

int			vm_valid_args(t_vm *vm, t_process *proc, t_op *op)
{
	int		step;
	int		i;

	if (!valid_type_args(proc, op))
		return (0);
	i = -1;
	step = OP_CODE_LEN + (op->is_type_args ? ARGS_CODE_LEN : 0);
	while (++i < op->args_num)
	{
		if (proc->type_args[i] == T_REG && !valid_reg_args(vm, proc, step))
			return (0);
		step += get_step(proc->type_args[i], op);
	}
	return (1);
}
