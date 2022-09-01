/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:43:16 by fbouleau          #+#    #+#             */
/*   Updated: 2022/08/28 22:06:13 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"

char	**g_base_nb;

int	make_base_nb(void)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		fd;

	fd = open("base_nb", O_RDONLY);
	if (fd == -1)
		return (0);
	ret = 0;
	ret = read(fd, buf, 103);
	buf[ret] = 0;
	g_base_nb = ft_split(buf, "\n");
	if (close(fd) == -1)
		return (0);
	return (1);
}

char	*find_path(int ac, char **av)
{
	if (ac == 2)
		return ("default.dict");
	else
		return (av[1]);
}

char	*find_nb_str(int ac, char **av)
{
	if (ac == 2)
	{
		if (!good_number_format(av[1]))
			return (0);
		else
			return (av[1]);
	}
	else
	{
		if (!good_number_format(av[2]))
			return (0);
		else
			return (av[2]);
	}
}

int	main(int argc, char **argv)
{
	t_mesh	*mesh_list;
	char	*path;
	char	*nb_str;
	int		fd;

	if (argc < 2 || argc > 3)
		return (ft_error());
	path = find_path(argc, argv);
	nb_str = find_nb_str(argc, argv);
	if (!nb_str)
		return (ft_error());
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_dict_error());
	if (!make_base_nb())
		return (ft_error());
	mesh_list = ft_make_mesh_list(ft_parse_peers(fd, path));
	if (!good_dict_format(mesh_list))
		return (ft_dict_error());
	show_number(mesh_list, ft_atoi(nb_str), 32);
	ft_free_mesh_list(mesh_list);
	ft_free_tab_2d(g_base_nb);
	if (close(fd) == -1)
		return (ft_dict_error());
	return (1);
}
