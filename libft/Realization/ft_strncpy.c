/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:14:36 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/06 14:59:19 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *new_str;

	new_str = dst;
	while (len--)
	{
		if (*(src))
			*(new_str++) = *(src++);
		else
			*(new_str++) = '\0';
	}
	return (dst);
}
