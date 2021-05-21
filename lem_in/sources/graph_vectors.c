/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:44:34 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:14:25 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Сравнение векторов.
** @param vector1 первый вектор.
** @param vector2 второй вектор.
** @return равны ли вектора: 0 - no, 1 - yes.
*/

int			equals_vector(t_vector vector1, t_vector vector2)
{
	return ((vector1.x == vector2.x && vector1.y == vector2.y) ? 1 : 0);
}

/*
** Создание вектора.
** @param x координата x.
** @param y координата y.
** @return вектор с координатами.
*/

t_vector	create_vector(int x, int y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
