/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:33:19 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:33:53 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_skipdelim(char const *str, int *i)
{
	while (str[*i] == 32 || (str[*i] > 8 && str[*i] < 13))
		(*i)++;
}

static int		ft_findmaxword(char const *str)
{
	int max_word;
	int cur_word;
	int i;

	i = -1;
	max_word = 0;
	while (str[++i])
	{
		ft_skipdelim(str, &i);
		cur_word = 0;
		while ((str[i] != 32) && (str[i] <= 8 || str[i] >= 13) && str[i++])
			cur_word++;
		if (cur_word > max_word)
			max_word = cur_word;
		i--;
		if (!str[i])
			break ;
	}
	return (max_word);
}

static int		ft_wordcount(char const *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
		if ((str[i] != 32) && (str[i] <= 8 || str[i] >= 13) &&
			(str[i + 1] == 32 || (str[i + 1] > 8 && str[i + 1] < 13) ||
			!str[i + 1]))
			count++;
	return (count);
}

static void		ft_fillarray(char **result, char const *str)
{
	int k;
	int j;
	int i;

	i = -1;
	k = 0;
	j = 0;
	while (str[++i])
	{
		ft_skipdelim(str, &i);
		k = 0;
		while ((str[i] != 32) && (str[i] <= 8 || str[i] >= 13) && str[i])
			result[j][k++] = str[i++];
		result[j++][k] = '\0';
		if (!str[i] || !result[j])
			break ;
	}
}

char			**ft_split_whitespaces(char const *str)
{
	char	**result;
	int		nwords;
	int		wordlen;

	nwords = ft_wordcount(str);
	wordlen = ft_findmaxword(str);
	result = ft_double_new(nwords, wordlen);
	if (!nwords)
		return (result);
	ft_fillarray(result, str);
	return (result);
}
