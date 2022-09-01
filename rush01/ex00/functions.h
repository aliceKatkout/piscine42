/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:41:33 by tbelleng          #+#    #+#             */
/*   Updated: 2022/08/21 21:20:28 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef functions
# define functions

int     check_param(char *param);
void    display_board(int **str);
int     **create_board(int rows, int cols);
int     *parse_params(char *input);
void    fill_zero(int   **board);
int     check_side(int nb, int par);
int     nb_is_valid_row(int *row, int index, int nb, int *param);
int     nb_is_valid_col(int **board, int index, int nb, int *param);
int	go_back(int **board, int i, int j, int *param);
int     pre_go_back(int **board, int i, int j, int *param);
int     solve(int **board, int *param);
void    pre_fill_one(int **board, int *param);
void    pre_fill_two(int **board, int *param);

#endif
