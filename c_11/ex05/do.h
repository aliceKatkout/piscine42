/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:42:59 by avedrenn          #+#    #+#             */
/*   Updated: 2022/09/01 12:48:44 by avedrenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_H
# define DO_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		is_space(char c);
int		is_numeric(char c);
int		ft_atoi(char *str);
int		add(int a, int b);
int		minus(int a, int b);
int		divide(int a, int b);
int		multiply(int a, int b);
int		modulo(int a, int b);

#endif
