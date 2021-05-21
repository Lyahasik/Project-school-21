/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:17:53 by dhorker           #+#    #+#             */
/*   Updated: 2021/01/16 15:20:39 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static float	shift(float center, float min, float max)
{
	float		shift;

	if (center > 0.0f)
	{
		if (0.0f - min < min)
			shift = 0.0f - min;
		else
			shift = 0.0f - min - center;
	}
	else if (center < 0.0f)
	{
		if (0.0f + max < max)
			shift = 0.0f + min;
		else
			shift = 0.0f + min + center;
	}
	return (shift);
}

static float	shift_z(t_object *object, t_triagle *triagle)
{
	float	min;
	float	max;
	float	center;
	int		triagle_id;
	int		vec_id;

	min = 1000000.0f;
	max = -1000000.0f;
	triagle_id = -1;
	while (++triagle_id < object->triagle_count)
	{
		vec_id = -1;
		while (++vec_id < 3)
		{
			min = (float)fmin(triagle[triagle_id][vec_id].position.z, min);
			max = (float)fmax(triagle[triagle_id][vec_id].position.z, max);
		}
	}
	center = (max - min) * 0.5f;
	return (shift(center, min, max));
}

static float	shift_y(t_object *object, t_triagle *triagle)
{
	float	min;
	float	max;
	float	center;
	int		triagle_id;
	int		vec_id;

	min = 1000000.0f;
	max = -1000000.0f;
	triagle_id = -1;
	while (++triagle_id < object->triagle_count)
	{
		vec_id = -1;
		while (++vec_id < 3)
		{
			min = (float)fmin(triagle[triagle_id][vec_id].position.y, min);
			max = (float)fmax(triagle[triagle_id][vec_id].position.y, max);
		}
	}
	center = (max - min) * 0.5f;
	return (shift(center, min, max));
}

static float	shift_x(t_object *object, t_triagle *triagle)
{
	float	min;
	float	max;
	float	center;
	int		triagle_id;
	int		vec_id;

	min = 1000000.0f;
	max = -1000000.0f;
	triagle_id = -1;
	while (++triagle_id < object->triagle_count)
	{
		vec_id = -1;
		while (++vec_id < 3)
		{
			min = (float)fmin(triagle[triagle_id][vec_id].position.x, min);
			max = (float)fmax(triagle[triagle_id][vec_id].position.x, max);
		}
	}
	center = (max - min) * 0.5f;
	return (shift(center, min, max));
}

void			update_center(t_object *object)
{
	object->transform.position.x = shift_x(object, object->triagle);
	object->transform.position.y = shift_y(object, object->triagle);
	object->transform.position.z = shift_z(object, object->triagle);
}
