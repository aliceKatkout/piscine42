/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:43:16 by fbouleau          #+#    #+#             */
/*   Updated: 2022/08/27 12:50:25 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <write_number.h>

int	main(int argc, char **argv)
{
	char	*path;
	int		fd;

	if (argc < 2 || argc > 3)
		return (ft_error());
	if (!good_number_format(argv[1]))
		return (ft_error());
	if (argc == 3 && !good_dict_format(argv[2]))
		return (ft_dict_error());
	path = "default.dict";
	if (argc == 3)
		path = argv[2];
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_dict_error());
	//
	//
	//
	if (close(fd) == -1)
		return (ft_dict_error());
	return (1);
}
