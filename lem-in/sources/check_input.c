/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:31:25 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:30:14 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Проверка обозначений комнат.
** @param line проверяемая строка.
** @return успешность операции: 0 - error, 2 - start, 3 - end.
*/

int	check_line_point(char *line)
{
	if (!ft_strcmp(line, "##start"))
	{
		return (2);
	}
	if (!ft_strcmp(line, "##end"))
	{
		return (3);
	}
	return (ft_out_message(ERR_POINT, 0));
}

/*
** Проверка на символы пробела, кроме пробела.
** @param line проверяемая строка.
** @param message сообщение об ошибке.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	check_spaces(char *line, char *message)
{
	if (ft_strchr(line, 9) || ft_strchr(line, 10)
		|| ft_strchr(line, 11) || ft_strchr(line, 12) || ft_strchr(line, 13))
	{
		return (ft_out_message(message, 0));
	}
	return (1);
}

/*
** Проверка на содержание пустой строки.
** @param data указатель для работы с данными алгоритма.
** @param lines массив строк.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	check_line_empty(t_data *data, char **lines)
{
	int	i;
	int	lines_amount;

	lines_amount = ft_str_char_count(data->input, '\n');
	i = -1;
	while (lines[++i])
	{
		lines_amount--;
	}
	if (lines_amount > data->is_spaces)
	{
		return (ft_out_message(ERR_EMPTY, 0));
	}
	return (1);
}
