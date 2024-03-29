/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:20:31 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/29 14:30:53 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_letters(char **strs, int size)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	ft_strcpy(char *dest, char *src)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (src[size] != '\0')
		size++;
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*res;

	if (size == 0)
	{
		res = (char *)malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	j = count_letters(strs, size) + (ft_strlen(sep)) * (size - 1) + 1;
	res = (char *)malloc(sizeof(char) * j);
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (j < size)
	{
		i += ft_strcpy(&res[i], strs[j]);
		if (j != (size - 1))
			i += ft_strcpy(&res[i], sep);
		j++;
	}
	res[i] = '\0';
	return (res);
}
/*
int	main()
{
	int	i = 0;
	char sep[] = " (c vre) ";
	char *strs[] = {"Jui bo", "et fort", "et je"};
	char * res;	
	res = ft_strjoin(i, strs, sep);
	printf("%s\n", res);
	free(res);
	return (0);
}
*/
