#include "fillit.h"

int		is_fit(char	**matrix, char **squard_to_fill, int y, int x)
{
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (matrix[row][col] == '#')
			{
				if (squard_to_fill[row + y][col + x] != '.' || squard_to_fill[row + y][col + x] == '\0')
					return (0);
			}
			col++;
		}

		row++;
	}

	return(1);
}

void	ok_here(char **squard_to_fill, char **matrix, int y, int x)
{
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (matrix[row][col] == '#')
			{
				squard_to_fill[row + y][col + x] = '1';
			}
			col++;
		}
		row++;
	}
}

void	multi_fit(char **squard_to_fill, char **matrix)
{
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (squard_to_fill[row][col] != '#')
			{
				if (is_fit(matrix, squard_to_fill, row, col) == 1)
				{
					
					ok_here(squard_to_fill, matrix, row, col);
				}
			}
			col++;
		}
		row++;
	}
}