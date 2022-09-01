/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:24:18 by avedrenn          #+#    #+#             */
/*   Updated: 2022/09/01 15:21:44 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(&tab[i], &tab[i + 1]);
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
    char *arr[5] = { "iiii", "dddd", "dddi", "aaa", '\0'};
    ft_sort_string_tab(arr);
    printf("Sorted array: \n");
    while (arr[i])
	    printf("%s, ", arr[i++]);
    return 0;
}
*/
