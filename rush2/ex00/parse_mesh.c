/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:04:15 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/28 21:41:45 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"

int	is_in_base(char *str)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (!ft_strcmp(g_base_nb[i], str))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (is_numeric(str[i]) && str[i] != 0)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}	
	return (res);
}

t_mesh	ft_mesh(char *line)
{
	t_mesh	res;
	char	**split_mesh;
	char	*sep;

	sep = ":";
	split_mesh = ft_split(line, sep);
	res.key = ft_atoi(split_mesh[0]);
	res.data = ft_str_duplicate(remove_firsts_white_space(split_mesh[1]));
	ft_free_tab_2d(split_mesh);
	return (res);
}

t_mesh	*ft_make_mesh_list(char **peers)
{
	t_mesh	*mesh_list;
	int		i;
	int		j;

	j = 0;
	i = 0;
	mesh_list = (t_mesh *)malloc(sizeof(t_mesh) * 33);
	while (peers[i] && j < 32)
	{
		if (is_in_base(peers[i]))
		{
			mesh_list[j] = ft_mesh(peers[i]);
			j++;
		}
		i++;
	}
	ft_free_tab_2d(peers);
	return (mesh_list);
}
