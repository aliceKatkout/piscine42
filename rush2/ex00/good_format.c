/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:11:50 by fbouleau          #+#    #+#             */
/*   Updated: 2022/08/28 21:17:55 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"

int	good_number_format(char *nb_str)
{
	char	ui_max[10];
	int		i;

	i = 0;
	while (nb_str[i])
		if (!is_numeric(nb_str[i++]))
			return (0);
	if (i > 10)
		return (0);
	if (i < 10)
		return (1);
	i = 0;
	while (i < 10)
	{
		ui_max[i] = "4294967295"[i];
		i++;
	}
	i = 0;
	while (i < 10 && nb_str[i] == ui_max[i])
		i++;
	if (i == 10 || nb_str[i] < ui_max[i])
		return (1);
	return (0);
}

int	good_dict_format(t_mesh *mesh_list)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (mesh_list[i].key != (unsigned int)(ft_atoi(g_base_nb[i])))
			return (0);
		i++;
	}
	return (1);
}
