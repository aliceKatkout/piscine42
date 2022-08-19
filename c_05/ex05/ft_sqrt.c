/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:19:01 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/19 10:31:40 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	
	if (nb == 1)
		return (1);
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
