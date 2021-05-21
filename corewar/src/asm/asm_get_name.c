/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:46:39 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/13 19:02:05 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static char		*skip_space_commit(t_data *data, char **save)
{
	char	*buff;

	while (1)
	{
		if (get_next_line(data->fd_r, &buff) == 0)
			exit(!!ft_printf(ERR_NO_NAME_COM));
		*save = buff;
		data->line_num++;
		while (*buff != 0 && (*buff == ' ' || *buff == '\t'))
			buff++;
		if (*buff == COMMENT_CHAR || *buff == ALT_COMMENT_CHAR || *buff == 0)
		{
			free_str_arr(save, NULL, 0);
			continue;
		}
		else if (ft_strncmp(buff, NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)) == 0)
			return (ft_strdup(buff + ft_strlen(NAME_CMD_STRING) + 1));
		else if (ft_strncmp(buff, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) == 0)
			return (ft_strdup(buff + ft_strlen(COMMENT_CMD_STRING) + 1));
		exit(!!ft_printf(ERR_NAME_COM, data->line_num));
	}
}

static void		checking_after_quotation(t_data *data, char *buff)
{
	int		i;

	i = 0;
	while ((buff[i] == ' ' || buff[i] == '\t') && buff[i] != 0)
		i++;
	if (buff[i] != 0 && buff[i] != COMMENT_CHAR
		&& buff[i] != ALT_COMMENT_CHAR)
		exit(!!ft_printf(ERR_NAME_COM, data->line_num));
	ft_bzero(buff - 1, ft_strlen(buff) + 1);
}

static char		*few_lines(t_data *data, char *tmp)
{
	char	*str;
	char	*buff;

	while (1)
	{
		if (get_next_line(data->fd_r, &buff) == 0)
			exit(!!ft_printf(ERR_NAME_COM, data->line_num));
		data->line_num++;
		if (ft_strchr(buff, '"') != 0)
		{
			checking_after_quotation(data, ft_strchr(buff, '"') + 1);
			str = ft_strjoin(tmp, buff);
			free_str_arr(&tmp, NULL, 0);
			free_str_arr(&buff, NULL, 0);
			tmp = str;
			break ;
		}
		str = ft_strjoin(tmp, buff);
		free_str_arr(&tmp, NULL, 0);
		free_str_arr(&buff, NULL, 0);
		tmp = str;
	}
	return (tmp);
}

static void		set_name_commit(t_data *data, char *tmp, int flag)
{
	int		help;

	help = 0;
	if (ft_strchr(tmp, '"'))
		checking_after_quotation(data, ft_strchr(tmp, '"') + 1);
	else
	{
		tmp = few_lines(data, ft_strdup(tmp));
		help = 1;
	}
	if (flag == 0 && data->name == 0)
		data->name = ft_strdup(tmp);
	else if (flag == 1 && data->comment == 0)
		data->comment = ft_strdup(tmp);
	else
		exit(!!ft_printf(ERR_NAME_COM, data->line_num));
	if (help)
		free(tmp);
}

void			get_name_commit(t_data *data)
{
	char	*str;
	char	*buff;
	int		i;
	int		k;

	k = -1;
	while (++k != 2)
	{
		i = 0;
		str = skip_space_commit(data, &buff);
		while (str[i] != 0 && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] != '"')
			exit(!!ft_printf(ERR_NAME_COM, data->line_num));
		if (ft_strstr(buff, NAME_CMD_STRING) != 0)
			set_name_commit(data, ft_strchr(str, '"') + 1, 0);
		else
			set_name_commit(data, ft_strchr(str, '"') + 1, 1);
		free_str_arr(&str, NULL, 0);
		free_str_arr(&buff, NULL, 0);
	}
}
