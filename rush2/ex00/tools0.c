/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:47:58 by fbouleau          #+#    #+#             */
/*   Updated: 2022/08/28 17:30:22 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_output(int output, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(output, str + i, 1);
		i++;
	}
}

void	ft_putstr(char *str)
{
	ft_putstr_output(1, str);
}

int	ft_error(void)
{
	ft_putstr_output(2, "Error\n");
	return (0);
}

int	ft_dict_error(void)
{
	ft_putstr_output(2, "Dict Error\n");
	return (0);
}
