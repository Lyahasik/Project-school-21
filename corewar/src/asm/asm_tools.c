/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:39:42 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/14 08:35:58 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

t_data		*get_data(t_data *data)
{
	static t_data *help_data = 0;

	if (!help_data)
		help_data = data;
	return (help_data);
}

/*
**	free(str) == 0;
**	free(arr) == 1;
**	free(str) && free(arr) == 2;
*/

void		free_str_arr(char **str, char ***arr, int flag)
{
	int		i;

	if ((flag == 0 || flag == 2) && *str != 0)
	{
		free(*str);
		*str = 0;
	}
	if ((flag == 1 || flag == 2) && arr != 0 && *arr != 0)
	{
		i = 0;
		while (arr[0][i])
		{
			free(arr[0][i]);
			arr[0][i] = 0;
			i++;
		}
		free(*arr);
		*arr = 0;
	}
}

char		*add_spaces(char **str)
{
	char	*buff;
	int		i;
	int		j;

	buff = (char*)ft_memalloc(sizeof(char) * 2 * (ft_strlen(*str) + 1));
	i = 0;
	j = 0;
	while (str[0][i])
	{
		if (str[0][i] == '%' || (i > 0 && str[0][i - 1] == ',')
			|| (i > 1 && str[0][i - 1] == ':'
			&& ft_strchr(LABEL_CHARS, str[0][i - 2])))
		{
			buff[j] = ' ';
			j++;
		}
		buff[j] = str[0][i];
		j++;
		i++;
	}
	return (buff);
}

char		*set_output_name(char *s)
{
	char	*name;
	char	*str;

	if (ft_strlen(s) < 2)
		exit(!!ft_printf(ERR_OUT_NAME));
	name = ft_strdup(s);
	str = ft_strrchr(name, '.');
	if (str == NULL)
		exit(!!ft_printf(ERR_OUT_NAME));
	if (ft_strncmp(str, ".s", 3))
		exit(!!ft_printf(ERR_OUT_NAME));
	else
		ft_bzero(str, 2);
	str = name;
	name = ft_strjoin(str, ".cor");
	free_str_arr(&str, NULL, 0);
	return (name);
}

void		free_data(t_data *data)
{
	t_operation		*op;
	t_label			*label;

	free_str_arr(&data->name, NULL, 0);
	free_str_arr(&data->comment, NULL, 0);
	while (data->op)
	{
		op = data->op->next;
		free(data->op);
		data->op = op;
	}
	while (data->label)
	{
		label = data->label->next;
		free(data->label->name);
		free(data->label);
		data->label = label;
	}
	free(data);
}
