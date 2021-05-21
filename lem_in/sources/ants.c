/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:22:45 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/05 16:14:26 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Пропуск всех строк до абзаца с комнатами.
** @param lines маcсив строк.
** @return номер первой строки с комнатами.
*/

int	skip_ants(char **lines)
{
	int	i;

	i = -1;
	while (lines[++i])
	{
		if ((lines[i][0] == '#' && lines[i][1] == '#')
			|| ft_str_char_count(lines[i], ' ') == 2)
			break ;
	}
	return (--i);
}

/*
** Заполнение значения муравьев.
** @param data указатель для работы с данными алгоритма.
** @param line обрабатываемая строка.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	find_ants(t_data *data, char *line)
{
	if (data->ants_num > 0)
	{
		return (1);
	}
	if (line[0] == '#')
	{
		if (line[1] == '#')
		{
			return (ft_out_message(ERR_ANTS_NUM, 0));
		}
		return (1);
	}
	if (line[0] >= '0' && line[0] <= '9' && ft_check_atoi_int(line))
	{
		data->ants_num = ft_atoi(line);
		return (1);
	}
	return (ft_out_message(ERR_ANTS_NUM, 0));
}
