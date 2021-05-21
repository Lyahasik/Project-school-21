/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 07:17:11 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/13 19:00:42 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int			is_label(char *s)
{
	int		i;
	int		len;

	if (!s)
		exit(!!ft_printf(ERR_LAST_LBL));
	len = (int)ft_strlen(s);
	if (len < 2 || s[len - 1] != LABEL_CHAR)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		if (ft_strchr(LABEL_CHARS, s[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

static void	get_next(t_label *label, t_data *data)
{
	char	*s;
	int		res;

	res = 0;
	while ((res = clean_line(data, &s)) > 0 && ft_strlen(s) < 1)
	{
		data->line_num++;
		free_str_arr(&s, NULL, 0);
	}
	if (res == 2)
		exit(!!ft_printf(ERR_NO_N));
	if (res == 0)
	{
		label->position = data->full_size;
		return ;
	}
	data->line_num++;
	label->position = get_labels_instructions(data, s);
	free_str_arr(&s, NULL, 0);
}

int			get_label(t_data *data, char **tmp, int tmp_len)
{
	t_label	*label;
	int		label_pos;

	label = set_label(&data->label, tmp[0]);
	label_pos = label->position;
	if (tmp_len > 1 && is_label(tmp[1]))
		label->position = get_label(data, &tmp[1], tmp_len - 1);
	else if (tmp_len > 1 && is_instruction(tmp[1]))
		label->position = get_instruction(data, &tmp[1],
								is_instruction(tmp[1]), tmp_len - 1);
	else if (tmp_len > 1)
		exit(!!ft_printf("ERROR: %s at line %d\n",
				tmp[1], data->line_num));
	else if (tmp_len < 2)
		get_next(label, data);
	label->position = (label_pos == -1) ? label->position : label_pos;
	return (label->position);
}

int			get_labels_instructions(t_data *data, char *str)
{
	int			i;
	int			res;
	char		**tmp;
	char		*space_str;

	space_str = add_spaces(&str);
	tmp = ft_split_whitespaces(space_str);
	free_str_arr(&space_str, NULL, 0);
	i = 0;
	while (tmp[i])
		i++;
	res = 0;
	if (is_label(tmp[0]))
		res = get_label(data, tmp, i);
	else if (is_instruction(tmp[0]) != 0)
		res = get_instruction(data, tmp, is_instruction(tmp[0]), i);
	else if (str[0] != '#')
		exit(!!ft_printf(ERR_NO_READ_2, data->line_num, str));
	free_str_arr(NULL, &tmp, 1);
	return (res);
}
