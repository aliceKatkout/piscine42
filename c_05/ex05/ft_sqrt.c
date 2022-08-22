/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:19:01 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/22 10:33:53 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	long int	i;

	if (nb == 1)
		return (1);
	i = 2;
	while (i < nb)
	{
		if (i * i == nb)
			return ((int)i);
		else
			i ++;
	}
	return (0);
}
