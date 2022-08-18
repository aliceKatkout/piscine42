/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:38:41 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/18 19:00:10 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	minus;

	minus = 1;
	res = 0;
	i = 0;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	while (str[i] != '\0' && !is_numeric(str[i]))
	{
		if (str[i] == '-')
			minus *= -1;
		if (!(str[i] == '-' || str[i] == '+'))
			return (0);
		i++;
	}
	while (is_numeric(str[i]) && str[i] != 0)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}	
	return (res * minus);
}

//int	main(int argc, char *argv[])
//{
//	if (argc > 0)
//		printf("%d\n", ft_atoi(argv[1]));
//	return (0);
//}
