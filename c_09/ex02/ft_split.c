/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:01:36 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/30 15:52:06 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && !is_sep(str[i], charset))
			i++;
		while (str[i] && is_sep(str[i], charset))
			i ++;
		j++;
	}
	return (j);
}

char	*ft_strdup(char *src, int start, char *charset)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (src[start + size] && !is_sep(src[start + size], charset))
		size ++;
	res = (char *)malloc(sizeof (char) * (size + 1));
	if (!res)
		return (0);
	while (src[start + i] && i < size)
	{
		res[i] = src[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		cw;

	i = 0;
	cw = count_word(str, charset);
	res = (char **)malloc(sizeof(char *) * (cw + 1));
	if (!res)
		return (0);
	j = 0;
	while (str[i + 1] && j < cw)
	{
		if (i == 0 && !is_sep(str[i], charset))
		{
			res[j] = ft_strdup(str, i, charset);
			j++;
		}		
		else if (!is_sep(str[i + 1], charset) && is_sep(str[i], charset))
			res[j++] = ft_strdup(str, i + 1, charset);
		i++;
	}
	res[j] = 0;
	return (res);
}
