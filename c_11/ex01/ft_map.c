/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:45:14 by avedrenn          #+#    #+#             */
/*   Updated: 2022/09/01 09:56:35 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int ( *f)(int))
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * length);
	if (!res)
		return (0);
	while (i < length)
	{
		res[i] = (*f)(tab[i]);
		i ++;
	}
	return (res);
}

/*
#include <stdio.h>
int ft(int n)
{
	return (n * 2);
}
int	main()
{
	int tab[4] = {1,2,3,4};
	int (*pf)(int);
	int* res;
	int i = 0;
	pf = &ft;
	res = ft_map(tab, 4, pf);
	while (i < 4)
		printf("%d,", res[i++]);

}
*/
