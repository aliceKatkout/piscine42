/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:48:03 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/22 16:19:02 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	if (range == NULL)
		return (-1);
	i = 0;
	while (i < size && min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (size);
}
