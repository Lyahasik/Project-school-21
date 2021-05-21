/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:10:56 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:10:58 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_add(t_vm *vm, t_process *proc)
{
	int		value;
	int		reg_1;
	int		reg_2;
	int		reg_3;

	PROC_STEP += ARGS_CODE_LEN;
	reg_1 = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	reg_2 = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	reg_3 = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	value = PROC_REG[reg_1 - 1] + PROC_REG[reg_2 - 1];
	proc->carry = (value == 0 ? 1 : 0);
	PROC_REG[reg_3 - 1] = value;
}
