/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:21:16 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/11 10:50:34 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_display(int i, int j, int k)
{
	char	str[3];

	str[0] = i + '0';
	str[1] = j + '0';
	str[2] = k + '0';
	write(1, &str, 3);
	if (i == 7 && j == 8 && k == 9)
	{
		return ;
	}
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 9)
	{
		j = i + 1;
		while (j <= 9)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_display(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
