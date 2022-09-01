/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_peers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:09:26 by avedrenn          #+#    #+#             */
/*   Updated: 2022/08/28 22:48:37 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_number.h"

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_w(char *str, char *sep)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && !is_sep(str[i], sep))
			i++;
		while (str[i] && is_sep(str[i], sep))
			i++;
		w++;
	}
	return (w);
}

char	*ft_strdup(char *src, int start, char *sep)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (src[start + size] && !is_sep(src[start + size], sep))
		size ++;
	res = (char *)malloc(sizeof (char) * (size + 1));
	if (!res)
		return (0);
	while (src[start + i] && i < size)
	{
		res[i] = src[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *sep)
{
	char	**res;
	int		i;
	int		j;
	int		cw;

	i = 0;
	j = 0;
	cw = count_w(str, sep);
	res = (char **)malloc(sizeof(char *) * (cw + 1));
	if (!res)
		return (0);
	while (str[i + 1] && j < cw)
	{
		if (i == 0 && !is_sep(str[i], sep))
		{
			res[j] = ft_strdup(str, i, sep);
			j++;
		}
		else if (!is_sep(str[i + 1], sep) && is_sep(str[i], sep))
			res[j++] = ft_strdup(str, i + 1, sep);
		i++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_parse_peers(int fd, char *path)
{
	char	*buf;
	char	**peers;
	int		n;

	buf = 0;
	n = find_buf_size(fd, buf, path);
	buf = malloc(n + 1);
	if (!buf)
		return (0);
	read(fd, buf, n);
	buf[n] = 0;
	peers = ft_split(buf, "\n");
	free(buf);
	return (peers);
}
