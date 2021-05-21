/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:43:17 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 22:16:14 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	vector;

	vector.x = v1.y * v2.z - v1.z * v2.y;
	vector.y = v1.z * v2.x - v1.x * v2.z;
	vector.z = v1.x * v2.y - v1.y * v2.x;
	return (vector);
}
