/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_numbers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourrec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:09:10 by tbourrec          #+#    #+#             */
/*   Updated: 2022/08/28 18:01:04 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"

int	search_index(t_mesh *mesh_list, unsigned int nb, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (mesh_list[i].key == nb)
			return (i);
		i++;
	}
	return (0);
}

void	show_billion(t_mesh *mesh_list, unsigned int nb, int size)
{
	if (nb % 10 != 0)
		ft_putstr(mesh_list[search_index(mesh_list, (nb % 10), size)].data);
	write(1, " ", 1);
	ft_putstr(mesh_list[search_index(mesh_list, 1000000000, size)].data);
}

void	show_million(t_mesh *mesh_list, unsigned int nb, int size)
{
	int	i;

	if (nb / 100 != 0)
	{
		ft_putstr(mesh_list[search_index(mesh_list, (nb / 100), size)].data);
		write(1, " ", 1);
		ft_putstr(mesh_list[search_index(mesh_list, 100, size)].data);
		nb %= 100;
		if (nb % 100 != 0)
			write(1, " and ", 5);
	}
	if (nb / 10 != 0 && (nb > 10 && nb < 20))
		ft_putstr(mesh_list[search_index(mesh_list, nb, size)].data);
	else if (!(((nb / 10) * 10) == 0))
	{
		i = search_index(mesh_list, ((nb / 10) * 10), size);
		ft_putstr(mesh_list[i].data);
		if ((nb % 10) != 0)
			write(1, "-", 1);
	}
	if (nb % 10 != 0 && !(nb > 10 && nb < 20))
		ft_putstr(mesh_list[search_index(mesh_list, (nb % 10), size)].data);
	write(1, " ", 1);
	ft_putstr(mesh_list[search_index(mesh_list, 1000000, size)].data);
}

void	show_thousand(t_mesh *mesh_list, unsigned int nb, int size)
{
	int	i;

	if (nb / 100 != 0)
	{
		ft_putstr(mesh_list[search_index(mesh_list, (nb / 100), size)].data);
		write(1, " ", 1);
		ft_putstr(mesh_list[search_index(mesh_list, 100, size)].data);
		nb %= 100;
		if (nb % 100 != 0)
			write(1, " and ", 5);
	}
	if (nb / 10 != 0 && (nb > 10 && nb < 20))
		ft_putstr(mesh_list[search_index(mesh_list, nb, size)].data);
	else if (!(((nb / 10) * 10) == 0))
	{
		i = search_index(mesh_list, ((nb / 10) * 10), size);
		ft_putstr(mesh_list[i].data);
		if ((nb % 10) != 0)
			write(1, "-", 1);
	}
	if (nb % 10 != 0 && !(nb > 10 && nb < 20))
		ft_putstr(mesh_list[search_index(mesh_list, (nb % 10), size)].data);
	write(1, " ", 1);
	ft_putstr(mesh_list[search_index(mesh_list, 1000, size)].data);
}

void	show_hundred(t_mesh *mesh_list, unsigned int nb, int size)
{
	int	i;

	if (nb / 100 != 0)
	{
		ft_putstr(mesh_list[search_index(mesh_list, (nb / 100), size)].data);
		write(1, " ", 1);
		ft_putstr(mesh_list[search_index(mesh_list, 100, size)].data);
		nb %= 100;
		if (nb % 100 != 0)
			write(1, " and ", 5);
	}
	if (nb / 10 != 0)
	{
		i = search_index(mesh_list, ((nb / 10) * 10), size);
		ft_putstr(mesh_list[i].data);
		if ((nb % 10) != 0)
			write(1, "-", 1);
	}
	if (nb % 10 != 0)
		ft_putstr(mesh_list[search_index(mesh_list, (nb % 10), size)].data);
}
