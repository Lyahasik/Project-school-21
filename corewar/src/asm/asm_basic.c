/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:10:11 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/14 11:39:20 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static int		my_save(char **dst, int res)
{
	*dst = ft_strdup("");
	return (res);
}

int				clean_line(t_data *data, char **dst)
{
	char		*buff;
	char		*str;
	char		**arr;
	int			res;

	res = get_next_line(data->fd_r, &buff);
	if (res == 0)
		return (res);
	str = ft_strtrim(buff);
	free_str_arr(&buff, NULL, 0);
	if (str == NULL || ft_strlen(str) == 0)
		return (my_save(dst, res));
	arr = 0;
	if (str[0] == COMMENT_CHAR || str[0] == ALT_COMMENT_CHAR)
		*dst = ft_strdup("");
	else if (ft_strchr(str, COMMENT_CHAR))
		arr = ft_strsplit(str, COMMENT_CHAR);
	else
		arr = ft_strsplit(str, ALT_COMMENT_CHAR);
	if (arr != 0 && ft_strlen(arr[0]) > 0)
		*dst = ft_strdup(arr[0]);
	free_str_arr(&str, &arr, 2);
	return (res);
}

void			basic_transformations(t_data *data)
{
	char	*str;
	int		res;

	res = 0;
	str = 0;
	get_name_commit(data);
	while ((res = clean_line(data, &str)) > 0)
	{
		data->line_num++;
		if (ft_strlen(str) > 0)
			get_labels_instructions(data, str);
		if (res == 2 && ft_strlen(str) != 0)
			exit(!!ft_printf(ERR_NO_N));
		free_str_arr(&str, NULL, 0);
	}
	free_str_arr(&str, NULL, 0);
	if (data->label == 0 && data->op == 0)
		exit(!!ft_printf(ERR_NO_OP));
	my_check(data);
}
