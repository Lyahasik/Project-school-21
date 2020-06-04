/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:57:47 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 14:50:00 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t num)
{
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	new_str1 = (unsigned char*)str1;
	new_str2 = (unsigned char*)str2;
	while (num--)
	{
		if (*(new_str1) > *(new_str2))
			return (*(new_str1) - *(new_str2));
		if (*(new_str1++) < *(new_str2++))
			return (*(--new_str1) - *(--new_str2));
	}
	return (0);
}
