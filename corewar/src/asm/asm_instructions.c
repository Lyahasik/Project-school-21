/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:51:36 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/10 19:05:22 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static int			is_instruction_2(char *s)
{
	if (ft_strcmp(s, "fork\0") == 0)
		return (12);
	else if (ft_strcmp(s, "lld\0") == 0)
		return (13);
	else if (ft_strcmp(s, "lldi\0") == 0)
		return (14);
	else if (ft_strcmp(s, "lfork\0") == 0)
		return (15);
	else if (ft_strcmp(s, "aff\0") == 0)
		return (16);
	else
		return (0);
}

int					is_instruction(char *s)
{
	if (ft_strcmp(s, "live\0") == 0)
		return (1);
	else if (ft_strcmp(s, "ld\0") == 0)
		return (2);
	else if (ft_strcmp(s, "st\0") == 0)
		return (3);
	else if (ft_strcmp(s, "add\0") == 0)
		return (4);
	else if (ft_strcmp(s, "sub\0") == 0)
		return (5);
	else if (ft_strcmp(s, "and\0") == 0)
		return (6);
	else if (ft_strcmp(s, "or\0") == 0)
		return (7);
	else if (ft_strcmp(s, "xor\0") == 0)
		return (8);
	else if (ft_strcmp(s, "zjmp\0") == 0)
		return (9);
	else if (ft_strcmp(s, "ldi\0") == 0)
		return (10);
	else if (ft_strcmp(s, "sti\0") == 0)
		return (11);
	else
		return (is_instruction_2(s));
}

static t_operation	*set_instruction(t_data *data, int inst_id, int op_id)
{
	t_operation *op;

	op = data->op;
	while (op != NULL && op->next != NULL)
	{
		op_id++;
		op = op->next;
	}
	if (op == NULL)
	{
		data->op = (t_operation*)ft_memalloc(sizeof(t_operation));
		op = data->op;
	}
	else
	{
		op->next = (t_operation*)ft_memalloc(sizeof(t_operation));
		op_id++;
		op = op->next;
	}
	op->instruction_id = inst_id;
	op->unique_id = op_id;
	op->position = data->full_size;
	return (op);
}

static void			set_operation_size(t_operation *op)
{
	int		i;

	i = 0;
	op->size = 1;
	while (i < MAX_ARG)
	{
		op->size += op->arg_size[i];
		i++;
	}
	op->size += (op->octet != 0);
}

int					get_instruction(t_data *data, char **tmp,
								int inst_id, int tmp_len)
{
	t_operation *op;

	if (inst_id == 0)
		return (0);
	if (tmp_len < 2)
		exit(!!ft_printf(ERR_NO_ARG, data->line_num));
	op = set_instruction(data, inst_id, 1);
	get_arguments(op, &tmp[1], tmp_len - 1, data);
	set_operation_size(op);
	data->full_size += op->size;
	return (op->position);
}
