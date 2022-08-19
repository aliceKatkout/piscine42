/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:22:25 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/14 16:24:44 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	n;
	int	i;

	i = 0;
	while (*(str + i))
	{
		n = str[i];
		if (!('A' <= n && n <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}