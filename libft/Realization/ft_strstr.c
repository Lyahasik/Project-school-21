/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:19:52 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 14:45:03 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*found_entry;
	char	*str;

	str = (char*)haystack;
	if (!*(needle))
		return ((char*)haystack);
	while (*(str))
	{
		i = 0;
		if (*(str) == *(needle))
		{
			found_entry = (char*)str;
			while (*(str++) == needle[i] && needle[i])
				i++;
		}
		if (needle[i] == '\0')
			return (found_entry);
		else if (i)
			str = ++found_entry;
		str++;
	}
	return (0);
}
