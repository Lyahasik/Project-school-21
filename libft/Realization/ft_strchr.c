/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:01:24 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/07 19:02:14 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*new_str;

	new_str = (char*)str;
	while (*new_str)
		if (*new_str++ == c)
			return (--new_str);
	if (*new_str == c)
		return (new_str);
	return (0);
}
