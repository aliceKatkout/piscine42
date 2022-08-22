/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:37:22 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/22 10:48:51 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

long int	ft_is_square_lim(int nb)
{
	long int	i;

	i = 0;
	while (i < nb)
	{
		if (i * i == nb)
			return ((int)i + 1);
		i++;
	}
	return ((int)i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	limit;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	limit = ft_is_square_lim(nb);
	while (i < limit)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
