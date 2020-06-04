/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:48:43 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 19:30:44 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst == src)
		return (dst);
	new_dst = (unsigned char*)dst;
	new_src = (unsigned char*)src;
	if (new_dst <= new_src)
		while (len--)
			*(new_dst++) = *(new_src++);
	else
	{
		new_dst = new_dst + len - 1;
		new_src = new_src + len - 1;
		while (len--)
			*(new_dst--) = *(new_src--);
	}
	return (dst);
}
