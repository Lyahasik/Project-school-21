/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:04:45 by lyahasik          #+#    #+#             */
/*   Updated: 2020/11/10 21:09:03 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Заполнение целочисленного массива числом
*/

void	ft_numset(int *array, int number, int size)
{
	int	i;

	if (array == NULL)
	{
		ft_putstr("Error: ft_numset NULL\n");
	}
	i = -1;
	while (++i < size)
		array[i] = number;
}
