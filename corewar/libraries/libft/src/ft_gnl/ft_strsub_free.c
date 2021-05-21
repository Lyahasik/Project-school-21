/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:43:32 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:35:19 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strsub_free(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s || !(sub = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	ft_strdel((char**)(&s));
	return (sub);
}
