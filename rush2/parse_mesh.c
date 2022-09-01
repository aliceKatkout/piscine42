/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:04:15 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/27 19:58:52 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"

char	**make_base_nb()
{
	char	base_nb[33][300];
	int	i;

	i = 0;
	while (i < 10)
	{
		base_nb[j][0] = i + 48;
		base_nb[j][1] = 0;
		i++;
		j++;
	}
	// remplir
	base_nb[29] = "1000";
	base_nb[30] = "1000000";
	base_nb[31] = "1000000000";
	base_nb[32] = "1000000000000";
	base_nb[33] = "\0";
	return (base_nb);
}

int	is_in_base(char *str, )
{
	// check si le debut de str 
	// while is_numeric
	// ft_compare(char str et base_nb)
	return(0); // ou 1 sinon
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

t_mesh	*ft_mesh(char *line)
{
	t_mesh	res;
	char	**split_mesh;
	char	*sep;

	sep = ":";
	split_mesh = ft_split(line, sep);
	
	res.key = ft_atoi(split_mesh[0]);
	// res.value = split_mesh[1] mais faut faire une fonction pour enlever les espaces au debut
	res.value = "coucou";	
	return (res);
}

t_mesh	*ft_make_mesh_list(char **peers)
{
	t_mesh  *mesh_list;
	int 	i;
	int	j;

	j = 0;
	i = 0;
	mesh_list = (t_mesh *)malloc(sizeof(t_mesh) * 33);
	while (peers[i] && j < 32)
	{
		if (is_in_base(peers[i]))
		{
			//check valid
			mesh_list[j] = ft_mesh(peers[i]);
			j++;
		}
		i++;
	}
	mesh_list[33] = 0;
	return (mesh_list);
}
