#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int    check_param(char *param)
{
        int i;

        i = 0;
        while (param[i])
        {
                if((param[i] >= '5' || param[i] <= '0') && param[i] != 32)
                {
                        return (0);
                }
                i++;
        }
        return (1);
}

void    display_board(int **str)
{
        int i;
        int l;

        i = 0;
        l = 0;
        while (l <= 3)
        {
                while (i <= 3)
                {
                        write(1, &str[l][i], 1);
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
	//Allocates number or row * sizeof int*
	board = malloc(sizeof(int*) * rows);
	//Protect malloc
	if (board == NULL)
		return (0);
	//Allocates number of column * size int for each row
	i = 0;
	while (i < cols)
	{
		board[i] = malloc(sizeof(int) * cols);
		if(board[i] == NULL)
			return (0);
		i ++;
	}
	return board;
}

int	*parse_params(char *input, int i)
{
	int	*res;
	int	j;

	res = malloc(sizeof(int) * 8);
                if(res == NULL)
                        return (0);

	j = 0;
	while(j < 8)
	{
		if(input[i] != ' ')
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
			board[i][j] = 48;
			j++;
		}
		i++;
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

int	check_row(int *row, int index, int *row_par)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if(row[i] == row[i + 1])
			return (0);
		i++;
	}
	if(!check_side(row[0], row_par[index]))
		return (0);
	if(!check_side(row[3], row_par[index + 4]))
		return (0);
	return(1);
}

int	check_column(int **board, int index, int *col_par)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		if(board[j][index] == row[j + 1][index])
			return (0);
                j++;
        }
        if(!check_side(board[0][index], col_par[index]))
                return (0);
        if(!check_side(board[3][index], col_par[index + 4]))
                return (0);
        return(1);

}

int	is_valid(int **board, int *col_par, int *row_par, int guess)
{
	int	res;
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		if (!check_row(board[i], i, row_par))
			return(0);
		else if (!check_column(board, i, col_par))
			return (0);
		else
			i++;
	}
	return (1);
}
void	guess_number(int **board, int *col_par, int *row_par, int nb)
{
	
}

void	solve(int **board, int *col_par, int *row_par)
{
	
}


int	main(int argc, char *argv[])
{
	int	**board;
	int	*col_par;
	int	*row_par;

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
	col_par = parse_params(argv[1], 0);
	row_par = parse_params(argv[1], 16);

	fill_zero(board);
	display_board(board);	
	free(col_par);
	free(row_par);
	free(board);
	return (0);
}
