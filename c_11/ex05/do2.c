/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:42:35 by avedrenn          #+#    #+#             */
/*   Updated: 2022/09/01 10:54:34 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else if (nb < 0)
	{	
		write(1, "-", 1);
		ft_putnbr(nb * -1);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	minus;

	minus = 1;
	res = 0;
	i = 0;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	while (str[i] != '\0' && !is_numeric(str[i]))
	{
		if (str[i] == '-')
			minus *= -1;
		if (!(str[i] == '-' || str[i] == '+'))
			return (0);
		i++;
	}
	while (is_numeric(str[i]) && str[i] != 0)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}	
	return (res * minus);
}
