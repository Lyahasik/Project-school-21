/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_matrix_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:08:23 by lyahasik          #+#    #+#             */
/*   Updated: 2020/11/10 21:08:34 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Вывод целочисленной матрицы
** @matrix - двумерный массив
** @x - ширина
** @y - высота
** @numbered - нумеровать строки: 1 - да
*/

void	ft_put_matrix_int(int **matrix, int x, int y, int numbered)
{
	int	i;
	int	j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		if (numbered == 1)
		{
			ft_putnbr(i + 1);
			ft_putstr("	- ");
		}
		while (++j < x)
		{
			ft_putnbr(matrix[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
