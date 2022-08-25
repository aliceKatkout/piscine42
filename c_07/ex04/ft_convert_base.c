/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:27:58 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/24 17:27:39 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_space(char c);
int		in_base(char c, char *base);
int		convert_to_dec(char c, char *base);
int		check_base(char *base);
void	ft_reverse(char *res);

int	ft_atoi_base(char *nbr, char *base, int sbf)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	res = 0;
	minus = 1;
	while (nbr[i] && is_space(nbr[i]))
		i++;
	while (nbr[i] && !in_base(nbr[i], base) && (nbr[i] == '+' || nbr[i] == '-'))
	{
		if (nbr[i] == '-')
			minus *= -1;
		i++;
	}
	while (nbr[i] && in_base(nbr[i], base))
	{
		res = res * sbf + convert_to_dec(nbr[i], base);
		i++;
	}
	return (res * minus);
}

char	*ft_malloc(int n, int sbt)
{
	int		nb;
	int		size_r;
	char	*res;

	size_r = 0;
	nb = n;
	size_r = 2;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		size_r++;
	}
	res = (char *)malloc(sizeof(char) * size_r * sbt);
	if (res == 0)
		return (res);
	return (res);
}

char	*ft_itoa_base(long int n, char *base, char *res, int size)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		if (n >= 0 && n < size)
			res[i] = base[n];
		else if (n < 0)
		{
			res[i] = '-';
			i ++;
			n = n * -1;
			res[i] = base[n % size];
		}
		else if (n >= size)
		{
			res[i] = base[n % size];
		}
		n = n / size;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sbt;
	int		sbf;
	int		n;
	char	*res;

	sbt = check_base(base_to);
	sbf = check_base(base_from);
	if (!sbt || !sbf)
		return (0);
	n = ft_atoi_base(nbr, base_from, sbf);
	res = ft_malloc(n, sbt);
	if (!res)
		return (0);
	if (n == 0)
	{
		res[0] = base_to[0];
		res[1] = '\0';
	}
	ft_itoa_base((long int)n, base_to, res, sbt);
	ft_reverse(res);
	return (res);
}
