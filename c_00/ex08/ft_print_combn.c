/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:48:59 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/14 15:16:28 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	power(int	nb,	int e)
{
	int	power;

	power = 1;
	while (e > 0)
	{
		power = power * nb;
		e --;
	}
	return power;
}

void	ft_putnbr(int nb)
{
	if (0 <= nb && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	compare(int nb, int *digit)
{
	while (nb > 9)
	{
		if ((nb/10)%10 < nb%10)
		{
			*digit = *digit + 1;
			compare(nb/10, digit);
		}
		else 
		{
			return (0);
		}		
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int	digit;
	int	*ptr;
	int	count;
	int	asc;

	digit = 1;
	ptr = &digit;
	count = power(10, n - 1);
	while (count < 789)
	{
		asc = compare(count, ptr);
		if (asc == 1)
			ft_putnbr(count);
		count ++;
	}

}

int main()
{
//	ft_print_combn(1);
	ft_print_combn(3);

}
