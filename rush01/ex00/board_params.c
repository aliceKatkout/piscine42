/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:57:21 by tbelleng          #+#    #+#             */
/*   Updated: 2022/08/21 21:16:43 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	check_param(char *param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		if ((param[i] >= '5' || param[i] <= '0') && param[i] != 32)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	display_board(int **str)
{
	int		i;
	int		l;
	char	n;

	i = 0;
	l = 0;
	while (l <= 3)
	{
		while (i <= 3)
		{
			n = str[l][i] + 48;
			write(1, &n, 1);
			write(1, " ", 1);
			i++;
		}
		i = 0;
		write(1, "\n", 1);
		l++;
	}
}

int	**create_board(int rows, int cols)
{
	int	**board;
	int	i;

	board = malloc(sizeof (int *) * rows);
	if (board == NULL)
		return (0);
	i = 0;
	while (i < cols)
	{
		board[i] = malloc(sizeof(int) * cols);
		if (board[i] == NULL)
			return (0);
		i ++;
	}
	return (board);
}

int	*parse_params(char *input)
{
	int	*res;
	int	j;
	int	i;

	res = malloc(sizeof(int) * 16);
	if (res == NULL)
		return (0);
	j = 0;
	i = 0;
	while (j < 16)
	{
		if (input[i] != ' ')
		{
			res[j] = input[i] - 48;
			j++;
		}
		i++;
	}	
	return (res);
}

void	fill_zero(int	**board)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}
