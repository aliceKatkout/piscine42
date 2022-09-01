/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:53:21 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/29 16:38:04 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		size;
	int		i;
	char	*res;

	size = 0;
	i = 0;
	while (str[size])
		size++;
	res = (char *) malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			j;

	res = (t_stock_str *)malloc(sizeof (t_stock_str) * (ac + 1));
	if (!res)
		return (0);
	j = 0;
	while (av[j] && j < ac)
	{
		res[j].size = ft_strlen(av[j]);
		res[j].str = av[j];
		res[j].copy = ft_strdup(av[j]);
		j++;
	}
	res[j].str = 0;
	return (res);
}
/*
int	main()
{
	char *strs[] = {"cou", "r", "gdeyu"};
	t_stock_str *res;
	res = ft_strs_to_tab(3, strs);
	ft_show_tab(res);
	if (res)
		free(res);
}
*/
