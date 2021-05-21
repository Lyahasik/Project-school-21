/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_validation_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:27:47 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/13 20:54:50 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/corewar.h"

void	valid_exec_size(t_vm *vm, t_file file, int i)
{
	if (PLAYER[i].exec_size != file.size)
		vm_error(9);
	if (PLAYER[i].exec_size == 0)
		vm_error(12);
	if (PLAYER[i].exec_size > CHAMP_MAX_SIZE)
		vm_error(10);
	if (!(PLAYER[i].exec_code = ft_memalloc(file.size)))
		vm_error(3);
}

char	**valid_filename(t_vm *vm, char **input, int *i, int *count)
{
	if (*i == MAX_PLAYERS - 1)
		vm_error(2);
	PLAYER[++(*i)].file = ft_strdup(*input);
	*count = (*count > 0 ? *count - 1 : *count);
	return (input);
}

char	**valid_flags(t_vm *vm, char **input, int *i, int *count)
{
	int num;

	if (!ft_strcmp(*input, "-n") && ft_is_number(*(input + 1)) &&
		(*i) < MAX_PLAYERS - 1 && !(*count) && *(input + 2))
	{
		PLAYER[(*i) + 1].n_on = 1;
		PLAYER[(*i) + 1].n_num = ft_atoi(*(++input));
		(*count)++;
	}
	else if (!ft_strcmp(*input, "-dump") && ft_is_number(*(input + 1)) &&
			(num = ft_atoi(*(input + 1))) >= 0 &&
			!ft_checkoverflow(num, *(input + 1)))
	{
		DUMP = num;
		++input;
	}
	else if (!ft_strcmp(*input, "-v"))
		VIS = 1;
	else
		vm_error(1);
	return (input);
}
