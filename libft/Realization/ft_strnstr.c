/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:15:48 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 12:16:52 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	char	*start;
	char	*new_str;

	if (!*(needle))
		return ((char*)haystack);
	i = 0;
	start = (char*)haystack;
	while (len-- && *start)
	{
		if (*(start) == needle[i] && i == 0)
			new_str = (char*)start;
		if (*(start) != needle[i] && i != 0)
		{
			start = ++new_str;
			len += i;
		}
		i = (*(start) == needle[i]) ? (i + 1) : 0;
		if (needle[i] == '\0')
			return (new_str);
		start++;
	}
	return (0);
}
