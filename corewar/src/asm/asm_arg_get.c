/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_arg_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:52:42 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/10 19:05:53 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static void	split_args(char **res, char ***tmp, int argc, int line_nr)
{
	int			i[3];

	i[0] = 0;
	i[2] = 0;
	while (tmp[i[0]] != NULL && i[0] < argc)
	{
		i[1] = 0;
		while (tmp[i[0]][i[1]] && i[2] <= MAX_ARG)
		{
			if (ft_strlen(tmp[i[0]][i[1]]) > 0)
			{
				res[i[2]] = ft_strdup(tmp[i[0]][i[1]]);
				i[2]++;
			}
			i[1]++;
		}
		free_str_arr(NULL, &tmp[i[0]], 1);
		i[0]++;
	}
	if (i[2] > MAX_ARG)
		exit(!!ft_printf(ERR_ARG_EXCESS, line_nr));
	res[i[2]] = 0;
}

static char	**get_clean(int argc, char **argv, int line_nr)
{
	char		**res;
	char		***tmp;
	int			i;

	if (MAX_ARG < 1)
		exit(!!ft_printf(ERR_MAX_VAL));
	res = (char**)ft_memalloc(sizeof(char*) * (MAX_ARG + 1));
	tmp = (char***)ft_memalloc(sizeof(char**) * (argc + 1));
	i = 0;
	while (i < argc)
	{
		tmp[i] = ft_strsplit(argv[i], ',');
		i++;
	}
	split_args(res, tmp, argc, line_nr);
	free(tmp);
	return (res);
}

int			get_arguments(t_operation *op, char **argv, int argc, t_data *data)
{
	char	**clean_args;
	int		i;
	int		args_qty;
	int		allowed_types;

	clean_args = get_clean(argc, argv, data->line_num);
	i = 0;
	while (clean_args[i] != NULL)
		i++;
	args_qty = ARGS_QTY[op->instruction_id];
	if (i != args_qty)
		exit(!!ft_printf(ERR_ARG_WRONG, data->line_num));
	allowed_types = ARGS_TYPES[op->instruction_id];
	if (set_arguments(op, clean_args, allowed_types, args_qty) < 0)
		exit(!!ft_printf(ERR_ARG_NEVAL, data->line_num));
	op->octet *= OCTAL[op->instruction_id];
	free_str_arr(NULL, &clean_args, 1);
	return (0);
}
