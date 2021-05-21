/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:17:36 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/05 23:00:05 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Вывод сообщения.
** input_1 строка.
** input_2 значение которое следует вернуть.
** return returned.
*/

void	ft_putstr_fast(char const *s)
{
	if (s != NULL)
	{
		write(1, s, ft_strlen(s));
	}
	else
	{
		write(2, "Error: ft_putstr_fast NULL\n", 28);
	}
}

int		ft_out_message(char *str, int returned)
{
	ft_putstr_fast(str);
	return (returned);
}
