/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:03:02 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:34:10 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int		ft_strchr_num(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (c != 0 && !str[i])
		return (-1);
	return (i);
}
