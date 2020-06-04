/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:57:18 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/09 22:07:32 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *str1, char const *str2, size_t n)
{
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	if (!str1 || !str2)
		return (0);
	if (n == 0)
		return (1);
	new_str1 = (unsigned char*)str1;
	new_str2 = (unsigned char*)str2;
	while (*(new_str1) == *(new_str2) && *new_str1 && n--)
		if ((*(new_str1++) == *(new_str2++) && !(n - 1)))
			return (1);
	return ((*(new_str1) == *(new_str2)) ? 1 : 0);
}
