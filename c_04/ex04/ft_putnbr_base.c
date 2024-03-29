/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:13:45 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/23 09:59:33 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <limits.h>

void	put_digit(int i, char *base)
{
	write(1, base + i, 1);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
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
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = 1;
		while (j + i < b)
		{
			if (base[i] != base[j + i])
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
	int				size;
	unsigned int	nbrl;

	size = check_base(base);
	if (size == 0)
		return ;
	if (nbr >= 0 && nbr < size)
		put_digit(nbr, base);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbrl = nbr * -1;
		if (nbr / size != 0)
			ft_putnbr_base((nbrl / size), base);
		put_digit((nbrl % size), base);
	}
	else if (nbr >= size)
	{
		ft_putnbr_base((nbr / size), base);
		put_digit((nbr % size), base);
	}
}
