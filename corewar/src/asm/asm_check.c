/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:53:29 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/10 19:05:15 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static void	check_size(t_operation *op)
{
	int		i;
	int		size;

	size = 1;
	size += (op->octet != 0);
	i = 0;
	while (i < MAX_ARG)
	{
		if (op->arg_type[i] < 0)
			exit(!!ft_printf(ERR_ARG_NEG, op->unique_id));
		if (op->arg_type[i] == 1 &&
			(op->arg[i] < 1 || op->arg[i] > 99))
			exit(!!ft_printf(ERR_REG, op->unique_id));
		if (op->arg_type[i] == 1)
			size++;
		if (op->arg_type[i] == 2)
			size += T_DIR_SIZE[op->instruction_id];
		else if (op->arg_type[i] == 3)
			size += 2;
		i++;
	}
	if (size != op->size)
		exit(!!ft_printf(ERR_SIZE_OP, op->unique_id));
}

static void	check_labels(t_operation *op, t_label *label, int arg_nr)
{
	t_label		*tmp;

	tmp = label;
	if ((op->arg_is_label[arg_nr] != 0 && op->arg_type[arg_nr] > 0) ||
		(op->arg_is_label[arg_nr] == 0 && op->arg_type[arg_nr] < 0))
		exit(!!ft_printf(ERR_ARG_LABEL));
	else if (op->arg_type[arg_nr] < 0)
		op->arg_type[arg_nr] = -op->arg_type[arg_nr];
	while (tmp != NULL && tmp->unique_id != op->arg_is_label[arg_nr])
		tmp = tmp->next;
	if (tmp == NULL)
		exit(!!ft_printf(ERR_LABEL_1, op->arg_is_label[arg_nr], op->unique_id));
	if (tmp->position == -1)
		exit(!!ft_printf(ERR_LABEL_2, tmp->name));
	op->arg[arg_nr] = tmp->position - op->position;
	if (op->arg_type[arg_nr] == 1 &&
		(op->arg[arg_nr] > 99 || op->arg[arg_nr] < 1))
		exit(!!ft_printf(ERR_OP_ARG, op->unique_id, arg_nr, op->arg[arg_nr]));
}

static void	check_arguments(t_operation *op, t_label *labels)
{
	int		max;
	int		args_qty;
	int		allowed;

	max = MAX_ARG;
	args_qty = ARGS_QTY[op->instruction_id];
	allowed = ARGS_TYPES[op->instruction_id];
	while (max > args_qty)
	{
		max--;
		if (op->arg_type[max] != 0)
			exit(!!ft_printf(ERR_MANY_ARG, op->unique_id));
		allowed /= 10;
	}
	while (max > 0)
	{
		max--;
		if (op->arg_type[max] < 0 || op->arg_is_label[max] != 0)
			check_labels(op, labels, max);
		if ((allowed % 10) != 0 && ((allowed % 10) & (op->arg_type[max] +
			(op->arg_type[max] > 2))) == 0)
			exit(!!ft_printf(ERR_ARG));
		allowed /= 10;
	}
}

static void	check_operation(t_data *data, t_operation *op)
{
	if (op->instruction_id > 16 || op->instruction_id < 1)
		exit(!!ft_printf(ERR_INST_LENGTH, op->instruction_id, op->unique_id));
	if (op->unique_id < 1)
		exit(!!ft_printf(ERR_ID, op->unique_id));
	if (op->next && op->unique_id - op->next->unique_id != -1)
		exit(!!ft_printf(ERR_OP, op->unique_id));
	if (op->position >= data->full_size)
		exit(!!ft_printf(ERR_OP_POS, op->unique_id, op->position,
						data->full_size));
	op->octet *= OCTAL[op->instruction_id];
}

void		my_check(t_data *data)
{
	t_operation		*operation;
	t_label			*labels;

	if (!data->name)
		exit(!!ft_printf(ERR_NO_NAME));
	if (!data->comment)
		exit(!!ft_printf(ERR_NO_COMMENT));
	if (ft_strlen(data->name) > PROG_NAME_LENGTH)
		exit(!!ft_printf(ERR_NAME_LENGTH, ft_strlen(data->name),
						PROG_NAME_LENGTH));
	if (ft_strlen(data->comment) > COMMENT_LENGTH)
		exit(!!ft_printf(ERR_COM_LENGTH, ft_strlen(data->comment),
						COMMENT_LENGTH));
	if (data->op)
	{
		operation = data->op;
		while (operation)
		{
			check_operation(data, operation);
			labels = data->label;
			check_arguments(operation, labels);
			check_size(operation);
			operation = operation->next;
		}
	}
}
