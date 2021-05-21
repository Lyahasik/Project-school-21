/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:34:47 by vcaterpi          #+#    #+#             */
/*   Updated: 2021/01/05 23:34:52 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/corewar.h"

int		mod_position(int position)
{
	position %= MEM_SIZE;
	position += (position < 0) ? MEM_SIZE : 0;
	return (position);
}

int		get_step(int type_arg, t_op *op)
{
	if (type_arg & T_REG)
		return (REG_LEN);
	else if (type_arg & T_DIR)
		return (op->t_dir_size);
	else if (type_arg & T_IND)
		return (IND_SIZE);
	return (0);
}
