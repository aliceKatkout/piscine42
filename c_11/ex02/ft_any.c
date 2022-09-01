/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:08:13 by avedrenn          #+#    #+#             */
/*   Updated: 2022/09/01 09:55:47 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int ( *f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int ft(char *str)
{
	int i =0;

	while (str[i])
	{
		if (str[i] == 'b')
			return (1);
		i ++;
	}
	return (0);
}
int	main()
{
	char *tab[4] = {"ni","no","na"};
	int (*pf)(char *);
	int res;
	pf = &ft;
	res = ft_any(tab, pf);
	printf("%d,", res);

}
*/
