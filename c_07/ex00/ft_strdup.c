/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:14:41 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/24 17:31:20 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_len(char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof (char) * (ft_len(src) + 1));
	if (res == 0)
		return (0);
	while (src[i] != 0)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

//int	main()
//{
//	char src[] = "Coucou :)";
//	char *res;
//
//	res = ft_strdup(src);
//	free(res);
//	return (0);
//}
