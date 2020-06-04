/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:05:27 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/24 18:02:48 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	new_str1 = (unsigned char*)str1;
	new_str2 = (unsigned char*)str2;
	while (n--)
	{
		if (!*(new_str1) && !*(new_str2))
			return (0);
		if (*(new_str1) > *(new_str2))
			return (*(new_str1) - *(new_str2));
		if (*(new_str1++) < *(new_str2++))
			return (*(--new_str1) - *(--new_str2));
	}
	return (0);
}
