/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:11:31 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:13:07 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_ldi(t_vm *vm, t_process *proc)
{
	int		reg;
	int		addr_1;
	int		addr_2;

	PROC_STEP += ARGS_CODE_LEN;
	addr_1 = get_op_args(vm, proc, 1, 1);
	addr_2 = get_op_args(vm, proc, 2, 1);
	reg = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	proc->reg[reg - 1] =
		get_byte_int(vm, PROC_POS + ((addr_1 + addr_2) % IDX_MOD), DIR_SIZE);
}
