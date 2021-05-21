/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:35:54 by antondob          #+#    #+#             */
/*   Updated: 2021/01/13 21:20:45 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_vm *vm;

	if (argc == 1)
		vm_error(1);
	vm = vm_create();
	vm_valid(vm, argv);
	vm_prep(vm);
	if (vm->visualizer == 1)
		launch_graphic(vm);
	else
		vm_war(vm);
	if (DUMP == -1)
		print_last_alive(vm);
	else
		vm_print_memory(vm);
	vm_free(&vm);
}
