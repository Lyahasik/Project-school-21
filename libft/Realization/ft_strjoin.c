/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:56:05 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/10 14:30:24 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*new_str;
	char	*begin;

	if (!str1 || !str2)
		return (0);
	if (!(new_str = ft_strnew(ft_strlen(str1) + ft_strlen(str2))))
		return (0);
	begin = new_str;
	while (*str1)
		*new_str++ = *str1++;
	while (*str2)
		*new_str++ = *str2++;
	*new_str = '\0';
	return (begin);
}
