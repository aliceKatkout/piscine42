/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:45:19 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/17 18:05:20 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (*(dest + j))
		j++;
	i = 0;
	while (*(src + i) && i < nb)
	{
		*(dest + j) = *(src + i);
		i ++;
		j ++;
	}
	*(dest + j) = 0;
	return (dest);
}
