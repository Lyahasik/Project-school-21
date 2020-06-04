/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:34:09 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 19:30:23 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst == src)
		return (dst);
	new_dst = (unsigned char*)dst;
	new_src = (unsigned char*)src;
	while (num--)
		*(new_dst++) = *(new_src++);
	return (dst);
}
