/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourrec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:04:30 by tbourrec          #+#    #+#             */
/*   Updated: 2022/08/27 13:24:20 by tbourrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "write_number.h"

void	show_number(t_mesh *mesh_list, unsigned int nb, int size)
{
	if (nb == 0)
	{
		ft_putstr(mesh_list[search_index(mesh_list, 0, size)].data);
		return ;
	}
	if (nb >= 1000000000)
	{
		show_billion(mesh_list, (nb / 1000000000), size);
		if (nb % 1000000000 != 0)
			write(1, " and ", 5);
	}	
	if ((nb % 1000000000) >= 1000000)
	{
		show_million(mesh_list, ((nb % 1000000000) / 1000000), size);
		if (nb % 1000000 != 0)
			write(1, " and ", 5);
	}
	if ((nb % 1000000) >= 1000)
	{
		show_thousand(mesh_list, ((nb % 1000000) / 1000), size);
		if (nb % 1000000 != 0)
			write(1, " and ", 5);
	}
	show_hundred(mesh_list, (nb % 1000), size);
}
