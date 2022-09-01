/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:04:15 by tbelleng          #+#    #+#             */
/*   Updated: 2022/08/21 21:17:22 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	pre_fill_one(int **board, int *param)
{
	int	i;
	int	j;
	int	nb;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		if (param[k] == 4)
		{
			nb = 1;
			while (i < 4)
			{
				board[i][k] = nb;
				nb ++;
				i++;
			}
		}
		k++;
	}
}

void	pre_fill_two(int **board, int *param)
{
	int	i;
	int	j;
	int	nb;
	int	k;

	i = 0;
	j = 8;
	k = 0;
	while (j >= 8 && j <= 11)
	{
		if (param[j] == 4)
		{
			nb = 1;
			while (k < 4)
			{
				board[i][k] = nb;
				nb ++;
				k++;
			}
		}
		i++;
		j++;
	}
}

int	check_side(int nb, int par)
{
	if ((par == 1 && nb != 4) || (par == 4 && nb != 1) || (par == 3 && nb == 4))
		return (0);
	if ((par == 2 && nb == 4) || (par == 3 && nb == 3))
		return (0);
	return (1);
}

int	nb_is_valid_row(int *row, int index, int nb, int *param)
{
	int		i;

	i = 0;
	while (i <= 3)
	{
		if (row[i] != 0)
		{
			if (nb == row[i])
				return (0);
		}
		i++;
	}
	if (index == 0 && !check_side(nb, param[index + 8]))
		return (0);
	if (index == 3 && !check_side(nb, param[index + 12]))
		return (0);
	return (1);
}

int	nb_is_valid_col(int **board, int index, int nb, int *param)
{
	int		j;

	j = 0;
	while (j <= 3)
	{
		if (board[j][index] != 0)
		{
			if (nb == board[j][index])
				return (0);
		}
		j++;
	}
	if (index == 0 && !check_side(nb, param[index]))
		return (0);
	if (index == 3 && !check_side(nb, param[index + 4]))
		return (0);
	return (1);
}
