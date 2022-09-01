/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:30:50 by fbouleau          #+#    #+#             */
/*   Updated: 2022/08/28 21:44:32 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"

char	*ft_str_duplicate(char *str)
{
	char	*dup;
	int		i;

	dup = malloc(ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	ft_free_mesh_list(t_mesh *mesh_list)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		free(mesh_list[i].data);
		i++;
	}
	free(mesh_list);
}

int	find_buf_size(int fd, char *buf, char *path)
{
	int	count;
	int	ret;

	count = 1;
	buf = malloc(BUF_SIZE);
	if (!buf)
		return (0);
	ret = read(fd, buf, BUF_SIZE);
	while (ret == BUF_SIZE)
	{
		free(buf);
		count++;
		buf = malloc(BUF_SIZE);
		if (!buf)
			return (0);
		ret = read(fd, buf, BUF_SIZE);
	}
	if (close(fd) == -1)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	free(buf);
	return (BUF_SIZE * (count - 1) + ret);
}
