/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:27:57 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/16 17:50:09 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	put_dec_to_hex(unsigned long n)
{
	unsigned long	quo;
	unsigned long	rem;
	char			*hex;
	char			res[17];
	int				i;

	hex = "0123456789abcdef";
	quo = n;
	i = 15;
	while (quo > 0)
	{
		quo = n / 16;
		rem = n % 16;
		res[i] = hex[rem];
		n = quo;
		i--;
	}
	res[16] = '\0';
	while (i >= 0)
	{
		res[i] = 48;
		i--;
	}
	put_str(res);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size == 0)
		return (addr);
	put_dec_to_hex((unsigned long) addr);
	write(1, ":", 1);
	return (addr);
}

//int	main()
//{
//	void	*addr;
//	char	str[] = "Coucou les petis potes !";
//	addr = &str;
//	ft_print_memory(addr, 16);
//}
