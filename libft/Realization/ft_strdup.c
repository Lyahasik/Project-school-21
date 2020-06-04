/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:03:14 by dhorker           #+#    #+#             */
/*   Updated: 2019/04/14 20:06:32 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = -1;
	if (!(dup = ft_strnew(ft_strlen(str))))
		return (0);
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
