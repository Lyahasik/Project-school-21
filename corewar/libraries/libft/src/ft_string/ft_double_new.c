/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:48:19 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:36:37 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_double_new(int nwords, int wordlen)
{
	char	**result;
	int		i;

	i = -1;
	if (!(result = (char**)malloc(sizeof(char*) * (nwords + 1))))
		return (NULL);
	while (++i < nwords)
	{
		if (!(result[i] = (char*)malloc(sizeof(char) * (wordlen + 1))))
		{
			ft_double_free(result, i);
			return (NULL);
		}
	}
	result[nwords] = NULL;
	return (result);
}
