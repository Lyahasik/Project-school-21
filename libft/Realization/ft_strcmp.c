/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:09:15 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/11 22:48:29 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	new_str1 = (unsigned char *)str1;
	new_str2 = (unsigned char *)str2;
	while (*(new_str1) == *(new_str2) && *new_str1)
	{
		new_str1++;
		new_str2++;
	}
	if (!*(new_str1) && !*(new_str2))
		return (0);
	return (*new_str1 - *new_str2);
}
