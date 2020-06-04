/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:30:07 by dhorker           #+#    #+#             */
/*   Updated: 2019/04/14 20:08:08 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	if ((size + 1) == 0 || !(new_str = (char*)ft_memalloc(size + 1)))
		return (0);
	ft_bzero(new_str, size + 1);
	return (new_str);
}
