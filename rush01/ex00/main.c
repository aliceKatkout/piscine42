/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:30:31 by rdias-ba          #+#    #+#             */
/*   Updated: 2022/08/21 21:16:09 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "functions.h"

int	pre_go_back(int **board, int i, int j, int *param)
{
	if (i == 4)
		return (1);
	if (board[i][j])
	{
		if (j == 3)
		{
			if (go_back(board, i + 1, 0, param))
				return (1);
		}
		else if (go_back(board, i, j + 1, param))
			return (1);
		return (0);
	}
	return (1);
}

int	go_back(int **board, int i, int j, int *param)
{
	int	next;

	pre_go_back(board, i, j, param);
	next = 1;
	while (next < 5)
	{
		if ((nb_is_valid_row(board[i], j, next, param)
				&& nb_is_valid_col(board, j, next, param)))
		{
			board[i][j] = next;
			if (j == 3)
			{
				if (go_back(board, i + 1, 0, param))
					return (1);
			}
			else if (go_back(board, i, j + 1, param))
				return (1);
		}
		board[i][j] = 0;
		next++;
	}
	return (0);
}

int	solve(int **board, int *param)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			nb = go_back(board, i, j, param);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	**board;
	int	*param;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!check_param(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	board = create_board(4, 4);
	param = parse_params(argv[1]);
	fill_zero(board);
	pre_fill_one(board, param);
	pre_fill_two(board, param);
	solve(board, param);
	display_board(board);
	free(param);
	free(board);
	return (0);
}
