/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atoi_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:25:52 by dhorker           #+#    #+#             */
/*   Updated: 2020/10/11 20:15:12 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Проверка, является ли строка числом в диапозоне integer.
** input_1 строка содержащая число.
** return (1) - OK, (0) - KO.
*/

int	ft_check_atoi_int(char *str)
{
	int	number;
	int	rezus;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	number = ft_atoi(str);
	rezus = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*(str + 1) && *str == '0')
		str++;
	if (*str < '0' || *str > '9' || ft_numlen(number) != (int)ft_strlen(str))
		return (0);
	if ((int)ft_strlen(str) == 10)
	{
		if (rezus < 0)
		{
			if (ft_strcmp("2147483648", str) < 0)
				return (0);
		}
		else if (ft_strcmp("2147483647", str) < 0)
			return (0);
	}
	return (1);
}
