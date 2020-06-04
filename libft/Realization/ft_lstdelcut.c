/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:02:15 by dhorker           #+#    #+#             */
/*   Updated: 2019/02/07 15:14:27 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelcut(t_list **start, t_list **alst)
{
	t_list	*list;

	if (alst)
	{
		list = *start;
		if (*start != *alst)
			while (list->next != *alst)
				list = list->next;
		if (list->next == *alst)
			list->next = (*alst)->next;
		else if (list->next != NULL)
			*start = (*start)->next;
		free((*alst)->content);
		free(*alst);
		*alst = NULL;
	}
}
