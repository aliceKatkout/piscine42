/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:10:25 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/13 09:31:51 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int	*a, int	*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	if (size % 2 == 0)
	{
		while (i != j + 1)
		{
			ft_swap(&tab[i], &tab[j]);
			i++;
			j--;
		}
	}
	else
	{
		while (i != j)
		{
			ft_swap(&tab[i], &tab[j]);
			i++;
			j--;
		}
	}
}
