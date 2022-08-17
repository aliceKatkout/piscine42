/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:13:45 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/17 12:21:39 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	b;
	int	j;

	b = 0;
	while (*(base + b))
		b++;
	if (b <= 1)
		return (0);
	i = 0;
	while (i < b)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j <= b)
		{
			if (base[i] != base[j + 1])
				j++;
			else
				return (0);
		}
		i++;
	}
	return (b);
}
	
void	ft_putnbr_base(int nbr, char *base)
{
	int size;

	size = check_base(base);
	if (size == 0)
		return;

	
}

int	main()
{
	char base1[8] = "abcdefgh";
	printf("check normal : %d\n", check_base(base1));
}
