/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sepchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:24:08 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/12 21:25:43 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sepchar(char const *str, unsigned char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		if (*str == c && *(str + 1) != c)
			i++;
	return (i);
}
