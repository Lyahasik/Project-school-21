/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:08:37 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/05 19:50:30 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_graphic	*graphic;

	if (!(graphic = create_graphic()))
	{
		return (0);
	}
	graphic->data->is_spaces = 1;
	if (!reading_result(graphic)
		|| !calculation_scale(graphic)
		|| !window_launch(graphic))
	{
		free_graphic(graphic);
		return (0);
	}
	free_graphic(graphic);
	return (0);
}
