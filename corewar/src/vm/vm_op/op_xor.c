/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:12:39 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:13:44 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_xor(t_vm *vm, t_process *proc)
{
	int		value_1;
	int		value_2;
	int		value;
	int		reg;

	PROC_STEP += ARGS_CODE_LEN;
	value_1 = get_op_args(vm, proc, 1, 1);
	value_2 = get_op_args(vm, proc, 2, 1);
	value = value_1 ^ value_2;
	proc->carry = (value == 0 ? 1 : 0);
	reg = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	PROC_REG[reg - 1] = value;
}
