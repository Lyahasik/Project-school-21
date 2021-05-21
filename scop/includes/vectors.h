/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:00:04 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/13 19:59:27 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H

# define VECTORS_H

# include <math.h>
# include "glew.h"
# include "glfw3.h"

typedef	struct	s_vec2
{
	GLfloat		x;
	GLfloat		y;
}				t_vec2;

typedef	struct	s_vec3
{
	GLfloat		x;
	GLfloat		y;
	GLfloat		z;
}				t_vec3;

typedef	struct	s_vec4
{
	GLfloat		x;
	GLfloat		y;
	GLfloat		z;
	GLfloat		w;
}				t_vec4;

t_vec2			vec2(GLfloat x, GLfloat y);
t_vec3			vec3(GLfloat x, GLfloat y, GLfloat z);
t_vec4			vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

t_vec3			vec3_inv(t_vec3 v);

t_vec3			vec3_sum(t_vec3 v1, t_vec3 v2);

t_vec3			vec3_div(t_vec3 v1, t_vec3 v2);

GLfloat			vec3_length(t_vec3 v);

t_vec3			vec3_norm(t_vec3 v);

t_vec3			vec3_cross(t_vec3 v1, t_vec3 v2);

#endif
