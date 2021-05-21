/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:26:02 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/09/16 14:11:19 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_free(char **str, int i)
{
	if (!str || !(*str))
		return ;
	while (i-- > 0)
		free(str[i]);
	free(str);
}
