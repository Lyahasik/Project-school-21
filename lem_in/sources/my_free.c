/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:24:10 by jsprouts          #+#    #+#             */
/*   Updated: 2020/11/15 17:44:12 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_paths(t_path *paths)
{
	t_cont *to_free_cont;
	t_path *to_free_path;

	while (paths != NULL)
	{
		while (paths->path != NULL)
		{
			to_free_cont = paths->path;
			paths->path = paths->path->next;
			free(to_free_cont);
		}
		to_free_path = paths;
		paths = paths->next;
		free(to_free_path);
	}
}
