/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:12:19 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:12:21 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_st(t_vm *vm, t_process *proc)
{
	int		value;
	int		reg;
	int		addr;

	PROC_STEP += ARGS_CODE_LEN;
	reg = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	value = PROC_REG[reg - 1];
	if (PROC_TA[1] == T_REG)
	{
		addr = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
		PROC_STEP += REG_LEN;
		PROC_REG[addr - 1] = value;
	}
	else
	{
		addr = get_byte_int(vm, PROC_POS + PROC_STEP, IND_SIZE);
		PROC_STEP += IND_SIZE;
		put_int_byte(vm, PROC_POS + (addr % IDX_MOD),
							value, proc->id_player);
	}
}
