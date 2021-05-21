/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:26:43 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:57:52 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Чтение входных данных.
** @param data указатель для работы с данными алгоритма.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	input_read(t_data *data)
{
	int		amount;
	int		amount_read;
	char	line[USHRT_MAX - 1];

	amount_read = 0;
	while ((amount = read(0, line, USHRT_MAX - 1)) > 0)
	{
		if (amount_read + amount > MAX_SIZE)
		{
			return (ft_out_message(ERR_OVERSIZE, 0));
		}
		ft_strncpy(data->input + amount_read, line, amount);
		amount_read += amount;
	}
	if (amount == -1)
	{
		return (ft_out_message(ERR_READ, 0));
	}
	return (1);
}

/*
** Обработка данных карты со входа.
** @param data указатель для работы с данными алгоритма.
** @return успешность операции: 0 - error, 1 - saccess.
*/

int	reading_map(t_data *data)
{
	if (input_read(data) == 0 || recording_data(data) == 0)
	{
		return (0);
	}
	return (1);
}
