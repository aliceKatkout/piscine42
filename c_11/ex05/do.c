/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:33:19 by avedrenn          #+#    #+#             */
/*   Updated: 2022/09/01 13:08:11 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do.h"

int	check_op(char *op, char *b)
{
	if (op[1] != 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (!(*op == '+' || *op == '-' || *op == '%' || *op == '/' || *op == '*'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (ft_atoi(b) == 0 && op[0] == '/')
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	else if (ft_atoi(b) == 0 && op[0] == '%')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	whatsop(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '/')
		return (2);
	else if (c == '*')
		return (3);
	else if (c == '%')
		return (4);
	else
		return (-1);
}

int	main(int argc, char **argv)
{
	int	(*ft_op[5])(int a, int b);
	int	res;
	int	op;

	ft_op[0] = add;
	ft_op[1] = minus;
	ft_op[2] = divide;
	ft_op[3] = multiply;
	ft_op[4] = modulo;
	if (argc != 4)
		return (0);
	if (!check_op(argv[2], argv[3]))
		return (0);
	op = whatsop(argv[2][0]);
	res = ft_op[op](ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
