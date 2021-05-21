/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_arg_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:45:32 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/10 19:05:11 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static int		only_allowed_chars(char *allowed, char *arg)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(arg);
	while (i < len)
	{
		if (!ft_strchr(allowed, arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		check_type(char *arg)
{
	int		res;

	res = 0;
	if (only_allowed_chars(ALLOWED_ARG_CHARS, arg) == 0)
		return (0);
	else if (arg[0] == 'r' && arg[1] != ':')
		res = 1;
	else if (arg[0] == 'r' && arg[1] == ':')
		res = -1;
	else if (arg[0] == '%' && arg[1] != ':')
		res = 2;
	else if (arg[0] == '%' && arg[1] == ':')
		res = -2;
	else if (ft_isdigit(arg[0]) || arg[0] == '-')
		res = 3;
	else if (arg[0] == ':')
		res = -3;
	if ((res == 1 && only_allowed_chars(ALLOWED_DIR_CHARS, &arg[1]) == 0)
		|| (res == 2 && only_allowed_chars(ALLOWED_DIR_CHARS, &arg[1]) == 0)
		|| (res == 3 && only_allowed_chars(ALLOWED_DIR_CHARS, arg) == 0))
		return (0);
	return (res);
}

static void		set_argument_value(t_operation *op, char *arg, int arg_nr,
						int arg_type)
{
	int		offset;
	t_data	*data;

	data = get_data(NULL);
	if (arg_type == 1 || arg_type == 2)
		offset = 1;
	else
		offset = 0;
	if (arg_type > 0 && (ft_strlen(&arg[offset]) < 1 ||
		(arg[offset] == '-' && (ft_strlen(&arg[offset]) < 2
		|| ft_strlen(&arg[offset]) > 11)) || ft_strlen(&arg[offset]) > 10))
		exit(!!ft_printf(ERR_ARG_NEVAL_2, arg, data->line_num));
	op->arg[arg_nr] = ft_atoi(&arg[offset]) * (arg_type > 0);
	if (arg_type < 0)
		arg_type = -arg_type;
	op->octet = op->octet | (arg_type << (6 - 2 * arg_nr));
	if (arg_type == 1 || arg_type == -1)
		op->arg_size[arg_nr] = 1;
	else if (arg_type == 3 || arg_type == -3)
		op->arg_size[arg_nr] = 2;
	else if (arg_type == 2 || arg_type == -2)
		op->arg_size[arg_nr] = T_DIR_SIZE[op->instruction_id];
}

static int		set_argument(t_operation *op, char *arg, int arg_nr,
						int allowed_type)
{
	int		arg_type;
	int		aux;
	char	*tmp;
	t_data	*data;
	t_label	*label;

	arg_type = check_type(arg);
	aux = (arg_type > 2) + (-1) * (arg_type < -2);
	if (arg_type == 0 || ((arg_type + aux) & allowed_type) == 0
		|| (arg_type == -1 && only_allowed_chars(LABEL_CHARS, &arg[2]) == 0)
		|| (arg_type == -2 && only_allowed_chars(LABEL_CHARS, &arg[2]) == 0)
		|| (arg_type == -3 && only_allowed_chars(LABEL_CHARS, &arg[1]) == 0))
		return (-1);
	if (arg_type < 0)
	{
		tmp = ft_strjoin(&arg[1 + (arg_type > -3)], ":\0");
		data = get_data(NULL);
		label = set_label(&data->label, tmp);
		op->arg_is_label[arg_nr] = label->unique_id;
		free_str_arr(&tmp, NULL, 0);
	}
	set_argument_value(op, arg, arg_nr, arg_type);
	op->arg_type[arg_nr] = arg_type;
	return (0);
}

int				set_arguments(t_operation *op, char **clean_args,
								int allowed_types, int args_qty)
{
	int		i;

	i = 0;
	while (i + args_qty < MAX_ARG)
	{
		allowed_types /= 10;
		i++;
	}
	while (args_qty > 0)
	{
		args_qty--;
		if (set_argument(op, clean_args[args_qty], args_qty, allowed_types % 10)
			< 0)
			return (-1);
		allowed_types /= 10;
	}
	return (1);
}
