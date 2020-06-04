/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:24:50 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 15:27:16 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *str, char c)
{
	char	*new_str;
	int		i;

	if (!str)
		return (0);
	while (*str == c)
		str++;
	i = ft_strlen(str) - 1;
	if (!ft_strlen(str))
		return (!(new_str = ft_strnew(++i))) ? 0 : new_str;
	while (str[i] == c)
		i--;
	if (!(new_str = ft_strnew(++i)))
		return (0);
	while (--i)
		new_str[i] = str[i];
	new_str[i] = str[i];
	return (new_str);
}
