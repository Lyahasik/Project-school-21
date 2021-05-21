/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_set_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 07:43:26 by jsprouts          #+#    #+#             */
/*   Updated: 2021/01/10 19:05:30 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static void	set_new_label(t_label **tmp, char *s, int id)
{
	tmp[0] = (t_label*)ft_memalloc(sizeof(t_label));
	tmp[0]->name = ft_strdup(s);
	tmp[0]->unique_id = id;
	tmp[0]->position = -1;
}

t_label		*set_label(t_label **label, char *str)
{
	t_label		*res;
	t_label		*tmp;
	int			id;

	id = 1;
	res = *label;
	if (ft_strlen(str) > 0)
		str[ft_strlen(str) - 1] = 0;
	while (res != NULL && res->next != NULL && ft_strcmp(res->name, str) != 0)
	{
		id++;
		res = res->next;
	}
	if (res != NULL && ft_strcmp(res->name, str) == 0)
		return (res);
	if (res != NULL)
		id++;
	set_new_label(&tmp, str, id);
	if (res == NULL)
		*label = tmp;
	else
		res->next = tmp;
	return (tmp);
}
