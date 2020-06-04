/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:54 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 15:26:46 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char	*new_str;
	int		i;

	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	i = ft_strlen(str) - 1;
	if (!ft_strlen(str))
		return (!(new_str = ft_strnew(++i))) ? 0 : new_str;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i--;
	if (!(new_str = ft_strnew(++i)))
		return (0);
	while (--i)
		new_str[i] = str[i];
	new_str[i] = str[i];
	return (new_str);
}
