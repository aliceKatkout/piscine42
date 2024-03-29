/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:45:04 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/14 16:45:26 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	n;
	int	i;

	i = 0;
	while (*(str + i))
	{
		n = str[i];
		if (!('a' <= n && n <= 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
