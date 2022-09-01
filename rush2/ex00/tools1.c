/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:08:47 by fbouleau          #+#    #+#             */
/*   Updated: 2022/08/28 21:16:54 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"

int	is_numeric(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && is_numeric(s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*remove_firsts_white_space(char *str)
{
	while (is_white_space(*str))
		str++;
	return (str);
}

void	ft_free_tab_2d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
