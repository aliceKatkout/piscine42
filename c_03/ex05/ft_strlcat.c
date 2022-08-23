/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:01:01 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/22 09:18:56 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	size_d;
	unsigned int	size_s;

	size_s = 0;
	size_d = 0;
	while (src[size_s] != '\0')
		size_s++;
	while (dest[size_d] != '\0')
		size_d++;
	if (!size)
		return (size_s);
	i = 0;
	while (src[i] && size_d + i < size - 1)
	{
		dest[size_d + i] = src[i];
		i ++;
	}
	dest[size_d + i] = 0;
	if (size_d > size)
		return (size_s + size);
	return (size_d + size_s);
}
