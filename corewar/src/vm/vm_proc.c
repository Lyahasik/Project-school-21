/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:41:01 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/05 23:41:14 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/corewar.h"
#include "../../header/graphic.h"

void			proc_step(t_process *proc)
{
	PROC_POS = mod_position(PROC_POS + PROC_STEP);
	PROC_STEP = 0;
	ft_bzero(PROC_TA, 12);
}

t_process		*proc_init(int id_player, int addr)
{
	t_process	*new;
	static int	proc_counter;

	if (!(new = ft_memalloc(sizeof(t_process))))
		vm_error(3);
	new->carry = 0;
	new->curr_position = addr;
	new->cycle_live = 0;
	new->cycle_op = 0;
	new->id = ++proc_counter;
	new->id_player = id_player;
	new->id_op = 0;
	new->next = NULL;
	new->reg[0] = -(id_player);
	return (new);
}

void			proc_insert(t_process **l_proc, t_process *proc)
{
	if (proc)
		proc->next = *l_proc;
	*l_proc = proc;
}

t_process		*proc_copy(t_process *proc, int addr)
{
	t_process	*new;
	int			i;

	i = -1;
	addr = mod_position(PROC_POS + addr);
	new = proc_init(proc->id_player, addr);
	while (++i < REG_NUMBER)
		new->reg[i] = PROC_REG[i];
	new->carry = proc->carry;
	new->cycle_live = proc->cycle_live;
	return (new);
}
