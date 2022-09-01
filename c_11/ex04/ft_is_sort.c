/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:07:39 by avedrenn          #+#    #+#             */
/*   Updated: 2022/09/01 10:26:06 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int ( *f)(int, int))
{
	int	asc;
	int	desc;
	int	i;

	i = 0;
	asc = 0;
	desc = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			asc ++;
		else if ((*f)(tab[i], tab[i + 1]) < 0)
			desc ++;
		i ++;
	}
	if (asc == length - 1 || desc == length - 1)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int ft(int a, int b)
{
	if (a < b)
		return (-1);
	else if ( a == b)
		return (0);
	else 
		return (1);
}
int	main()
{
	int tab[4] = {21,12,10,4};
	int (*pf)(int, int);
	int res;
	pf = &ft;
	res = ft_is_sort(tab, 4, pf);
	printf("%d,", res);

}

*/
