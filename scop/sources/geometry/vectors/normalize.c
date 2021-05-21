/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:41:53 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 22:16:06 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec3	vec3_norm(t_vec3 v)
{
	GLfloat	length_inv;

	length_inv = 1.0f / vec3_length(v);
	v.x *= length_inv;
	v.y *= length_inv;
	v.z *= length_inv;
	return (v);
}
