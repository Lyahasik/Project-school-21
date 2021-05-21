/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:00:53 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/06 00:10:16 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void	stage_free(void **stage)
{
	if (!*stage)
		return ;
	free(*stage);
	*stage = NULL;
}

void	players_free(t_player **players)
{
	if (!*players)
		return ;
	free(*players);
	*players = NULL;
}

void	process_free(t_process **process)
{
	t_process *tmp;

	if (!*process)
		return ;
	while (*process)
	{
		tmp = *process;
		*process = (*process)->next;
		free(tmp);
	}
}

void	vm_free(t_vm **vm)
{
	if (!*vm)
		return ;
	while (--(**vm).players_num >= 0)
	{
		free(((*vm)->players)[(**vm).players_num].file);
		free(((*vm)->players)[(**vm).players_num].exec_code);
	}
	players_free(&((*vm)->players));
	process_free(&((*vm)->processes));
	free(*vm);
	*vm = NULL;
}
