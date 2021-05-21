/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 00:38:49 by lyahasik          #+#    #+#             */
/*   Updated: 2020/12/04 01:53:02 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Поиск муравья по имени.
** @param graphic указатель для работы с данными графики.
** @param name имя муравья.
** @return указатель на муравья.
*/

t_ant	*find_ant(t_graphic *graphic, char *name)
{
	int	i;

	i = -1;
	while (++i < graphic->data->ants_num)
	{
		if (!ft_strcmp(graphic->ants[i].name, name))
			break ;
	}
	return (&(graphic->ants[i]));
}
