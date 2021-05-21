/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:04:42 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/06 17:08:55 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "graphic.h"

/*
** Запуск графики.
** @return 0 - error, 1 - ok.
*/

int	launch_graphic(t_vm *vm)
{
	if (!(vm->graphic = allocation_graphic()))
		return (0);
	if (!init_graphic(vm->graphic))
	{
		return (free_graphic(vm->graphic));
	}
	rendering(vm, vm->graphic, vm->graphic->sdl);
	free_graphic(vm->graphic);
	return (1);
}
