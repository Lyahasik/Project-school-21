/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:14:14 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/26 17:02:59 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	num;
	int			rhesus;
	int			i;

	while ((*(str) >= 9 && *(str) <= 13) || *(str) == 32)
		str++;
	rhesus = (*(str) == '-') ? -1 : 1;
	str = (*(str) == '-' || *(str) == '+') ? str + 1 : str;
	num = 0;
	i = 0;
	while (*(str) >= '0' && *(str) <= '9')
	{
		if (++i == 20 || (num >= 922337203685477580 && num * 10 + (*(str) - '0')
			< 922337203685477580))
			return (rhesus < 0 ? 0 : -1);
		num = num * 10 + (*(str++) - '0');
	}
	return ((int)num * rhesus);
}
