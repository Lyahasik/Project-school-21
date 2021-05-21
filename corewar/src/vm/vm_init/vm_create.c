/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:09:35 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:09:38 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

t_vm	*vm_create(void)
{
	t_vm	*vm;

	if (!(vm = ft_memalloc(sizeof(t_vm))))
		vm_error(3);
	if (!(PLAYER = ft_memalloc(sizeof(t_player) * MAX_PLAYERS)))
		vm_error(3);
	DUMP = -1;
	vm->n_loop_dead = CYCLE_TO_DIE;
	return (vm);
}
