/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:58:58 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:32:38 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Заполнение матрицы связей, проверка на повторяющиеся связи.
** @param data указатель для работы с данными алгоритма.
** @param lines проверяемые строки.
** @return успешность операции: 0 - error, 1 - saccess.
*/

static int	recording_connections(t_data *data, char **lines)
{
	int	room1;
	int	room2;

	room1 = -1;
	while (++room1 < data->rooms_amount)
		if (!ft_strcmp(data->rooms[room1].name, lines[0]))
			break ;
	if (room1 == data->rooms_amount)
		return (ft_out_message(ERR_LINK_INC, 0));
	room2 = -1;
	while (++room2 < data->rooms_amount)
		if (!ft_strcmp(data->rooms[room2].name, lines[1]))
			break ;
	if (room2 == data->rooms_amount)
		return (ft_out_message(ERR_LINK_INC, 0));
	if (data->connections[room1][room2] == 1)
		return (ft_out_message(ERR_LINK_DUP, 0));
	data->connections[room1][room2] = 1;
	data->connections[room2][room1] = 1;
	return (1);
}

/*
** Предпроверка имен комнат в связях.
** @param data указатель для работы с данными алгоритма.
** @param line проверяемая строка.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			filling_connections(t_data *data, char *line)
{
	char	**tempory;

	if (!(tempory = ft_strsplit(line, '-')))
		return (ft_out_message(ERR_MEM, 0));
	if (tempory[1][0] == '#' || tempory[1][0] == 'L')
	{
		ft_mem_free_two((void**)tempory);
		return (ft_out_message(ERR_ROOM_NAME, 0));
	}
	if (!ft_strcmp(tempory[0], tempory[1]))
		return (ft_out_message(ERR_ROOM_DNAME, 0));
	if (!recording_connections(data, tempory))
		return (ft_mem_free_two((void**)tempory));
	ft_mem_free_two((void**)tempory);
	return (1);
}

/*
** Проверка корректности ввода строки содержащей связи.
** @param data указатель для работы с данными алгоритма.
** @param line проверяемая строка.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int			processing_connections(t_data *data, char *line)
{
	int		i;
	char	**tempory;

	if (line[0] == '#')
		return ((line[1] == '#') ? ft_out_message(ERR_LINK_INC, 0) : 1);
	if (!ft_strchr(line, ' ') && check_spaces(line, ERR_LINK_SPACE)
		&& ft_strchr(line, '-') && ft_str_char_count(line, '-') == 1)
	{
		if (!(tempory = ft_strsplit(line, '-')))
			return (ft_out_message(ERR_MEM, 0));
		i = -1;
		while (tempory[++i])
		{
			if (tempory[i][0] == '#' || tempory[i][0] == 'L')
			{
				ft_mem_free_two((void**)tempory);
				return (ft_out_message(ERR_ROOM_NAME, 0));
			}
		}
		ft_mem_free_two((void**)tempory);
		return (1);
	}
	return (ft_out_message(ERR_LINK_INC, 0));
}
