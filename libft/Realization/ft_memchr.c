/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:56:22 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 14:30:31 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t num)
{
	unsigned char	*new_str;

	new_str = (unsigned char*)str;
	while (num--)
		if (*(new_str++) == (unsigned char)c)
			return (--new_str);
	return (0);
}
