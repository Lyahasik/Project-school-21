/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:53:31 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/21 14:42:11 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	char	*temp;

	temp = str1;
	while (*(temp))
		temp++;
	while (*(str2))
		*(temp++) = *(str2++);
	*(temp) = '\0';
	return (str1);
}
