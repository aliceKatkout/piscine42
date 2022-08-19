/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:01:01 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/17 17:56:06 by avedrenn         ###   ########.fr       */
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
	while (*(src + size_s))
		size_s++;
	while (*(dest + size_d))
		size_d++;
	i = 0;
	while (*(src + i) && (size_d + i) < size - 1)
	{
		*(dest + size_d + i) = *(src + i);
		i ++;
	}
	*(dest + size_d + i) = 0;
	if (size < size_d)
		return (size_s + size);
	else
		return (size_d + size_s);
	return (size + size_s);
}
