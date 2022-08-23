/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:27:58 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/23 18:22:49 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
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

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int 	sbt;
	int	sbf;
	int 	i;
	int	minus;

	i = 0;
	sbt = check_base(base_from);
	sbf = check_base(base_to);
	if (!sbt || !sbf)
		return (0);
	while (nbr[i] && is_space(str[i]))
		i++;
	while (nbr[i] && !in_base(str[i]) && (str[i] == '+' || str[i] == '-'))

}
