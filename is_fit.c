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
				printf("is fit? [%i][%i]: %i\n", row, col, is_fit(matrix, squard_to_fill, row, col));
			}
			col++;
		}
		row++;
	}
}