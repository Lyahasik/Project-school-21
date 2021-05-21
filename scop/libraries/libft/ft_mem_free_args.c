/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_free_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyahasik <lyahasik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:44:34 by lyahasik          #+#    #+#             */
/*   Updated: 2020/11/04 17:50:24 by lyahasik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mem_free_args(void *arg1, void *arg2, void *arg3, void *arg4)
{
	if (arg1)
		free(arg1);
	if (arg2)
		free(arg2);
	if (arg3)
		free(arg3);
	if (arg4)
		free(arg4);
	return (0);
}
