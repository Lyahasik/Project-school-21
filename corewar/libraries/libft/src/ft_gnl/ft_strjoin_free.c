/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:37:40 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:34:35 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	len_s1;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	if (!(join = ft_strnew(len_s1 + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[i - len_s1])
	{
		join[i] = s2[i - len_s1];
		i++;
	}
	join[i] = '\0';
	ft_strdel((char**)(&s1));
	ft_strdel((char**)(&s2));
	return (join);
}
