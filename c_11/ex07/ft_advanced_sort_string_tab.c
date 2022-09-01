/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:02:11 by avedrenn          #+#    #+#             */
/*   Updated: 2022/09/01 15:19:38 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int ( *cmp)(char *, char *))
{
	int	i;
	int	j;
	int	swap;

	j = 0;
	while (tab[j + 1])
	{
		i = 0;
		while (tab[i + 1])
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(tab + i, tab + i + 1);
				swap = 1;
			}
			i ++;
		}
		if (!swap)
			break ;
		j++;
	}
}

/*
#include <stdio.h>
int main()
{
	int i = 0;
	char *arr[5] = { "zzzzz", "vvvvv", "dddi", "xxuuu", '\0'};
	int (*cmp)(char *, char *);
	cmp = &ft_strcmp;
	ft_advanced_sort_string_tab(arr, cmp);
    printf("Sorted array: \n");
    while (arr[i])
	    printf("%s, ", arr[i++]);
    return 0;
}
*/
