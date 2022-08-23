/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:20:31 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/23 13:14:54 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
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
		while(strs[i][j])
		{
			c++;
			j++;
		}
		i++;
	}
	return (c);

}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *res;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = count_letters(strs, size) + (ft_strlen(sep) - 1) * (size - 1) + 1;
	if (size == 0)
		res = (char *)malloc(sizeof(char));
	res = (char *)malloc(sizeof(char) * j);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			res[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			res[k] = sep[j];
			j++;
			k++;
		}
		i++;
	}
	res[k] = '\0';	
	return (res);
}

int	main()
{
	int	i = 3;
	char sep[] = " et ";
	char *strs[] = {"manon", "noah", "alice"};
	char * res;	
	res = ft_strjoin(i, strs, sep);
	printf("%s\n", res);
	free(res);
	return (0);
}
