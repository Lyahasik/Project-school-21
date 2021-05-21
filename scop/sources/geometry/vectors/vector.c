/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:28:12 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:32:25 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec2	vec2(GLfloat x, GLfloat y)
{
	t_vec2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vec3	vec3(GLfloat x, GLfloat y, GLfloat z)
{
	t_vec3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vec4	vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	t_vec4	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return (vector);
}
