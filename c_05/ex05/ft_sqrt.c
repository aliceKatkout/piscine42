/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:19:01 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/18 18:36:09 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 2;
	while (i < nb)
	{
		if (i * i == nb)
			return (i);
		else
			i ++;
	}
	return (0);
}
