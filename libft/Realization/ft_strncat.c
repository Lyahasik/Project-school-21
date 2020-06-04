/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:13:46 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/07 18:47:30 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	char	*new_str;

	new_str = &str1[ft_strlen(str1)];
	while (*str2 && n--)
		*(new_str++) = *(str2++);
	*(new_str) = '\0';
	return (str1);
}
