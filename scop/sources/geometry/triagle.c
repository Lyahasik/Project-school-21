/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triagle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:29:54 by lyahasik          #+#    #+#             */
/*   Updated: 2021/01/16 12:44:03 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	triagle_uv(t_triagle *triagle,
						t_vec2 point1, t_vec2 point2, t_vec2 point3)
{
	(*triagle)[0].uv.x = point1.x;
	(*triagle)[0].uv.y = point1.y;
	(*triagle)[1].uv.x = point2.x;
	(*triagle)[1].uv.y = point2.y;
	(*triagle)[2].uv.x = point3.x;
	(*triagle)[2].uv.y = point3.y;
}

void	triagle_position(t_triagle *triagle,
						t_vec3 point1, t_vec3 point2, t_vec3 point3)
{
	(*triagle)[0].position.x = point1.x;
	(*triagle)[0].position.y = point1.y;
	(*triagle)[0].position.z = point1.z;
	(*triagle)[1].position.x = point2.x;
	(*triagle)[1].position.y = point2.y;
	(*triagle)[1].position.z = point2.z;
	(*triagle)[2].position.x = point3.x;
	(*triagle)[2].position.y = point3.y;
	(*triagle)[2].position.z = point3.z;
}
