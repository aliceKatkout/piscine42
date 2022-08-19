/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:36:33 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/12 14:43:24 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_swap(int	*a, int	*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if (tab[i] > tab[j])
		{
			ft_swap(&tab[i], &tab[j]);
		}
		i++;
		j++;
	}
	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if (tab[i] > tab[j])
		{
			ft_sort_int_tab(tab, size);
		}
		i++;
		j++;
	}	
}
