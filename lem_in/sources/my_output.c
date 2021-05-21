/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakarov <smakarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:25:01 by jsprouts          #+#    #+#             */
/*   Updated: 2020/12/05 12:05:30 by smakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_case(void *to_free)
{
	if (to_free != NULL)
		free(to_free);
	write(1, "\033[31mError\033[0m\n", 15);
	exit(0);
}

void	print_line(char *line)
{
	write(1, line, ft_strlen(line));
	write(1, "\n", 1);
}

void	print_ant_step(char *ant, char *room)
{
	int		ant_len;
	int		room_len;

	ant_len = ft_strlen(ant);
	room_len = ft_strlen(room);
	write(1, "L", 1);
	write(1, ant, ant_len);
	write(1, "-", 1);
	write(1, room, room_len);
	write(1, " ", 1);
	free(ant);
}

void	out_one_step(int i, char *name)
{
	char	*number;

	number = ft_itoa(i);
	write(1, "L", 1);
	write(1, number, ft_strlen(number));
	write(1, "-", 1);
	write(1, name, ft_strlen(name));
	write(1, " ", 1);
	free(number);
}
