/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:59:16 by dhorker           #+#    #+#             */
/*   Updated: 2020/11/12 19:01:26 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_char_count(char *str, char c)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (*str)
		{
			if (*str == c)
				i++;
			str++;
		}
	}
	return (i);
}
