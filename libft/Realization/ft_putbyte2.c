/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbyte2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:01:27 by dhorker           #+#    #+#             */
/*   Updated: 2019/02/06 18:10:41 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbyte2(short *num)
{
	int	size;

	if (num)
	{
		size = 16;
		while (--size >= 0)
		{
			write(1, (*num & (1 << size)) ? "1" : "0", 1);
			if (!(size % 8))
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	else
		write(2, "error\n", 6);
}
