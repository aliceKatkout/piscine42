/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:53:27 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/21 15:36:56 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_char_is_printable(char c)
{
	if (!(' ' <= c && c <= '~'))
	{
		return (0);
	}
	return (1);
}

void	convert_to_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_printable(str[i]))
			convert_to_hex(str[i]);
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
