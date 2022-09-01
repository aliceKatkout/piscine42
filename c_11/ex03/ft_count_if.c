/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:57:50 by avedrenn          #+#    #+#             */
/*   Updated: 2022/09/01 10:07:00 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int ( *f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if ((*f)(tab[i]))
			count ++;
		i++;
	}
	return (count);
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
	char *tab[3] = {"nib","nbo","nanb"};
	int (*pf)(char *);
	int res;
	pf = &ft;
	res = ft_count_if(tab, 3, pf);
	printf("%d,", res);

}
*/
