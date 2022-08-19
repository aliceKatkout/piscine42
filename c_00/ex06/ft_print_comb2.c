/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:21:28 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/13 10:20:46 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_joli(char	*tab)
{
	char	virg;

	virg = 44;
	write(1, tab, 5);
	if (tab[0] != 57 || tab[1] != 56 || tab[3] != 57 || tab[4] != 57)
	{
		write(1, &virg, 1);
		write(1, " ", 1);
	}
}

void	ft_display(int i, int j)
{
	char	tab[5];

	tab[2] = 32;
	if (i <= 9)
	{
		tab[0] = 48;
		tab[1] = i + 48;
	}
	else if (i > 9)
	{
		tab[0] = (i / 10) + 48;
		tab[1] = (i % 10) + 48;
	}
	if (j <= 9)
	{
		tab[3] = 48;
		tab[4] = j + 48;
	}
	else if (j > 9)
	{
		tab[3] = (j / 10) + 48;
		tab[4] = (j % 10) + 48;
	}
	ft_joli(tab);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_display(i, j);
			j++;
		}
		i++;
	}	
}
