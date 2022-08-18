/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:22:51 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/18 19:53:33 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	in_base(char c, char	*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c != base[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int	convert_to_dec(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
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
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 1;
		while (j + i <= b)
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	size;
	int	minus;

	size = check_base(base);
	if (size == 0)
		return (0);
	res = 0;
	i = 0;
	minus = 1;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	while (str[i] && !in_base(str[i], base) && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (in_base(str[i], base) && str[i] != 0)
	{	
		res = res * size + convert_to_dec(str[i], base);
		i++;
	}
	return (res * minus);
}
