/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:25:45 by fbouleau          #+#    #+#             */
/*   Updated: 2022/08/28 21:40:53 by fbouleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_NUMBER_H
# define WRITE_NUMBER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 4096

typedef struct s_mesh
{
	unsigned int	key;
	char			*data;
}	t_mesh;

extern char	**g_base_nb;

int		ft_strlen(char *str);

void	ft_putstr(char *str);

int		ft_error(void);

int		ft_dict_error(void);

int		good_number_format(char *nb_str);

int		is_numeric(char c);

char	*remove_firsts_white_space(char *str);

int		ft_strcmp(char *s1, char *s2);

char	**ft_split(char *str, char *sep);

int		ft_atoi(char *str);

t_mesh	*ft_make_mesh_list(char **peers);

int		search_index(t_mesh *mesh_list, unsigned int nb, int size);

void	show_billion(t_mesh *mesh_list, unsigned int nb, int size);

void	show_million(t_mesh *mesh_list, unsigned int nb, int size);

void	show_thousand(t_mesh *mesh_list, unsigned int nb, int size);

void	show_hundred(t_mesh *mesh_list, unsigned int nb, int size);

void	show_number(t_mesh *mesh_list, unsigned int nb, int size);

void	ft_free_tab_2d(char **tab);

char	*ft_str_duplicate(char *str);

void	ft_free_mesh_list(t_mesh *mesh_list);

char	**ft_parse_peers(int fd, char *path);

int		good_dict_format(t_mesh *mesh_list);

int		find_buf_size(int fd, char *buf, char *path);

#endif
