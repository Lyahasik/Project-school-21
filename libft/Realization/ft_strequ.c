/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:48:04 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/09 20:55:37 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *str1, char const *str2)
{
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	if (!str1 || !str2)
		return (0);
	new_str1 = (unsigned char*)str1;
	new_str2 = (unsigned char*)str2;
	while (*(new_str1) == *(new_str2) && *new_str1 && *new_str2)
	{
		new_str1++;
		new_str2++;
	}
	return (!*(new_str1) && !*(new_str2) ? 1 : 0);
}
