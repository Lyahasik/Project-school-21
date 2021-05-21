/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:12:26 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:14:24 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_sti(t_vm *vm, t_process *proc)
{
	int		value;
	int		reg;
	int		addr_1;
	int		addr_2;

	PROC_STEP += ARGS_CODE_LEN;
	reg = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	value = PROC_REG[reg - 1];
	addr_1 = get_op_args(vm, proc, 2, 1);
	addr_2 = get_op_args(vm, proc, 3, 1);
	put_int_byte(vm, PROC_POS + ((addr_1 + addr_2) % IDX_MOD),
		value, proc->id_player);
}
