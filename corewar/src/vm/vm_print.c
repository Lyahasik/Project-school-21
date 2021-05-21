/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:38:20 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:46:09 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/corewar.h"

void	vm_print_hex_test(void *mem, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		ft_printf("%0#10x:  ", i);
		j = -1;
		while (++j < 32 && i + j < size)
			ft_printf("%02x ", ((unsigned char *)(mem))[i + j]);
		ft_printf("\n");
		i += j;
	}
}

void	vm_print_memory(t_vm *vm)
{
	int i;
	int j;

	i = 0;
	ft_printf("\n");
	while (i < MEM_SIZE)
	{
		ft_printf("%0#10x:  ", i);
		j = -1;
		while (++j < 32 && i + j < MEM_SIZE)
			ft_printf("%02x ", STAGE[i + j]);
		ft_printf("\n");
		i += j;
	}
	ft_printf("\n");
}

void	vm_print_proc(t_process *proc)
{
	ft_printf("\n ------ Метасведения каретки ------ \n");
	ft_printf("Идентификатор\t\t\t| %d\n", proc->id);
	ft_printf("Код операции\t\t\t| %d\n", proc->id_op);
	ft_printf("Кол. циклов до OP\t\t| %d\n", proc->cycle_op);
	ft_printf("Текущая позиция относительная\t| %d\n", proc->curr_position);
}

void	print_last_alive(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
			vm->survivor_id,
			vm->players[vm->survivor_id - 1].name);
}
