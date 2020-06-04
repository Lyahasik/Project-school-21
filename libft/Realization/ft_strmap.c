/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:24:55 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/23 13:58:37 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*func)(char))
{
	char	*new_str;
	char	*begin;

	if (!str || !func)
		return (0);
	if (!(new_str = ft_strnew(ft_strlen(str))))
		return (0);
	begin = (char*)new_str;
	while (*str)
		*new_str++ = func(*(str++));
	*new_str = '\0';
	return (begin);
}
