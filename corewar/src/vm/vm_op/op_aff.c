/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:11:03 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:11:06 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void		op_aff(t_vm *vm, t_process *proc)
{
	int		reg;
	int		value;

	PROC_STEP += ARGS_CODE_LEN;
	reg = get_byte_int(vm, PROC_POS + PROC_STEP, REG_LEN);
	PROC_STEP += REG_LEN;
	value = PROC_REG[reg - 1];
	if (vm->is_aff)
		ft_printf("Aff: %c\n", (char)value);
}
