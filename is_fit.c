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
			if (matrix[row][col] == '#' || (matrix[row][col] > '0' && matrix[row][col] <= '9'))
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

void	ok_here(char **squard_to_fill, figure *f, int y, int x, int fig_counter)
{
	int		row;
	int		col;
	char	*sb_to_write;

	sb_to_write = ft_itoa(fig_counter);
	f->x = x;
	f->y = y;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (f->matrix[row][col] == '#')
			{
				squard_to_fill[row + y][col + x] = *sb_to_write;
			}
			col++;
		}
		row++;
	}
}

int		multiple_fit(char **squard_to_fill, figure *f,  int fig_counter)
{
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
				if (is_fit(f->matrix, squard_to_fill, row, col) == 1)
				{	
					ok_here(squard_to_fill, f, row, col, fig_counter);
					return (1);
				}
			col++;
		}
		row++;
	}
	return (0);
}

// mistake is here
int		can_i_shift(char **squard_to_fill, figure *f,  int fig_counter, int squard_size)
{
	int		row;
	int		col;
	int		is_it_first_time;

	row = f->y;
	is_it_first_time = 1;

	del_me(squard_to_fill, fig_counter);
	while (row < squard_size)
	{
		if (is_it_first_time == 1)
		{
			col = f->x + 1;
		}
		else
			col = 0;
		while (col < squard_size)
		{
				if (is_fit(f->matrix, squard_to_fill, row, col) == 1)
				{	
					f->x = col;
					f->y = row;

					// printf(" u can put here y %i\n", f->y );
					// printf(" u can put here x %i\n", f->x );
					return (1);
				}
			is_it_first_time = 0;
			col++;
		}
		row++;
	}
	return (0);
}
