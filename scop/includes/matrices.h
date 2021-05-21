/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:10:05 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/14 18:06:59 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H

# define MATRICES_H

# include "libft.h"
# include "vectors.h"
# include "messages.h"

typedef t_vec4	t_matrix4[4];

t_matrix4		*matrix4(t_vec4 column1, t_vec4 column2, t_vec4 column3,
				t_vec4 column4);
t_matrix4		*matrix4_identity();

t_vec4			matrix_mul4x1(t_matrix4 m, t_vec4 v);
void			matrix_mul4x4(t_matrix4 *matrix, t_matrix4 *m1, t_matrix4 *m2);

void			matrix_sum_4x4(t_matrix4 *m1, t_matrix4 m2);

t_matrix4		*matrix_scaling(t_vec3 scale);
t_matrix4		*matrix_rotation(t_matrix4 *m, t_vec3 degrees);
t_matrix4		*matrix_translation(t_vec3 position);

t_matrix4		*matrix_model(t_vec3 scale, t_vec3 rotate, t_vec3 position);
t_matrix4		*look_at(t_vec3 position, t_vec3 target);
t_matrix4		*perspective(float near, float far);

GLfloat			radians(float degrees);
GLfloat			degrees(float radians);

#endif
