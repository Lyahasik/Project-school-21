/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:43:27 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/09 22:48:43 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*new_str;
	int		i;

	if (!str)
		return (0);
	if ((new_str = ft_strnew(len)))
	{
		i = 0;
		while (len--)
			new_str[i++] = str[start++];
	}
	return (new_str);
}
