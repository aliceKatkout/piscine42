/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:18:27 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/19 13:02:54 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	size;
	int	i;
	int	j;

	if (min >= max)
		return (0);
	size = max - min;
	res = (int*)malloc(sizeof(int) * size);
	i = min;
	j = 0;
	while (i < max)
	{
		res[j] = i;
		i++;
		j++;
	}
	return (res);
}

int	main(void)
{
	int	*res;
	int	i;
	res = ft_range(-2, 20);
	for (i = 0; i < 22; i++)
		printf("%d\n", res[i]);
	free(res);
	return (0);
}
