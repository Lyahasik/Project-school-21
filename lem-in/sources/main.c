/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:01:57 by jsprouts          #+#    #+#             */
/*   Updated: 2020/12/05 16:57:57 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	free_and_return(t_data *data)
{
	free_data(data);
	return (0);
}

int			main(void)
{
	t_data	*data;

	if (!(data = create_data()) || !reading_map(data))
	{
		return (free_data(data));
	}
	step_in_paths(data);
	data->paths = get_paths(*data);
	if (data->paths == NULL)
	{
		if (data->connections[data->start][data->end] == 1)
			return (free_and_return(data));
		else
		{
			free_data(data);
			error_case(NULL);
		}
	}
	print_line(data->input);
	move_ants(*data);
	free_paths(data->paths);
	free_data(data);
	return (0);
}
