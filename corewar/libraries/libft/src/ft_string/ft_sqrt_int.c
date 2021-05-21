/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:08:30 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/13 00:07:41 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Вычисление целочисленного корня числа.
** @param number число.
** @return целочисенный корень.
*/

int		ft_sqrt_int(int number)
{
	int	result;

	result = 1;
	while (result * result <= number)
	{
		result++;
	}
	return (--result);
}
