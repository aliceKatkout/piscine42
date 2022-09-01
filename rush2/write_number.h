/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:25:45 by fbouleau          #+#    #+#             */
/*   Updated: 2022/08/27 17:51:52 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_NUMBER_H
# define WRITE_NUMBER_H

# include <unistd.h>
# include <stdlib.h>
# include  <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 4096

typedef struct s_mesh
{
	unsigned int	key;
	char	*data;
}	t_mesh;

int		ft_strlen(char *str);

void	ft_putstr(char *str);

int		ft_error(void);

int		ft_dict_error(void);

int		good_number_format(char *nb_str);

int		good_dict_format(char *file_name);

int		is_numeric(char c);

#endif
