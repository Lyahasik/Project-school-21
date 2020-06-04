/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:45:25 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 19:18:55 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	char	*new_str;
	char	*begin;
	char	i;

	if (!str)
		return (0);
	if (!(new_str = ft_strnew(ft_strlen(str))))
		return (0);
	i = 0;
	begin = (char*)new_str;
	while (*str)
		*new_str++ = func(i++, *(str++));
	*new_str = '\0';
	return (begin);
}
