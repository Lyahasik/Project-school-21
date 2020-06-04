/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:18:36 by dhorker           #+#    #+#             */
/*   Updated: 2018/12/23 18:44:59 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_help(char ***array, char *str, int num, char c)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= num - 1)
	{
		j = 0;
		while (str[j] != c && str[j])
			j++;
		if (!((*array)[i] = ft_strnew(j)))
		{
			while (**array)
			{
				free(**array);
				**array = NULL;
				(*array)++;
			}
			return ;
		}
		ft_strncpy((*array)[i], str, j);
		str = str + j;
		while (*str == c)
			str++;
	}
	(*array)[i] = NULL;
}

char		**ft_strsplit(char const *str, char c)
{
	char	**array;
	char	*new_str;
	int		num;

	if (!str || !(new_str = ft_strctrim(str, c)))
		return (0);
	num = ft_sepchar(new_str, c) + 1;
	if (!*new_str)
		num--;
	if (!(array = (char **)malloc((num + 1) * sizeof(char *))))
		return (0);
	ft_help(&array, new_str, num, c);
	free(new_str);
	return (array);
}
