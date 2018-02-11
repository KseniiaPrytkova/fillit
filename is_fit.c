#include "fillit.h"

int		is_fit(char	**matrix, char **squard_to_fill, int x, int y)
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
				if (squard_to_fill[row + x][col + y] == '#' || squard_to_fill[row + x][col + y] == '\0')
					return (0);
			}
			col++;
		}

		row++;
	}

	return(1);
}