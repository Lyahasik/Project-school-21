/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:18:36 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/07 20:13:20 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*new_str;

	new_str = NULL;
	while (*(str))
	{
		if (*(str) == c)
			new_str = (char *)str;
		str++;
	}
	if (*(str) == c)
		new_str = (char *)str;
	return ((c > 127 || c < 0 || !new_str) ? 0 : new_str);
}
