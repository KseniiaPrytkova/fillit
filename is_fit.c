#include "fillit.h"

int		is_fit(char	**matrix, char **squard_to_fill, int y, int x)
{
	int		row;
	int		col;
	int 	is_it_first_time;
	int catch_fig;

	row = 0;
	is_it_first_time = 1;
	catch_fig = 0;

	while (row < 4)
	{
		
		col = 0;
		while (col < 4)
		{

			if (is_it_first_time == 1)
			{
				if (matrix[0][1] == '#' && matrix[1][1] == '#' && matrix[2][0] == '#' && matrix[2][1] == '#'
					&& x == 3)
					{
						printf("GOT U!!!\n");
						x = x - 1;
						printf("%i\n", x );
						catch_fig = 2;
						// is_it_first_time = 0;
		
					}
				else if (matrix[0][2] == '#' && matrix[1][0] == '#' && matrix[1][1] == '#' && matrix[1][2] == '#'
						&& x == 3)
				{
					printf("GOT U1!!!\n");
						x = x - 2;
						printf("%i\n", x );
						catch_fig = 3;
				}
				else if (matrix[0][2] == '#' && matrix[1][0] == '#' && matrix[1][1] == '#' && matrix[1][2] == '#'
						&& x == 4)
				{
					printf("GOT U2!!!\n");
						x = x - 2;
						printf("%i\n", x );
						catch_fig = 4;
				}
				else
					is_it_first_time = 0;
					
			}
			printf("MATRIX[ROW][COL]:%c\n", matrix[row][col]);
			if (matrix[row][col] == '#' || (matrix[row][col] > '0' && matrix[row][col] <= '9') || (matrix[row][col] > 'A' && matrix[row][col] <= 'Z'))
			{
				// printf("is_fit says UPPSSS!!!\n" );
				printf("i'm in is_fit: %c\n", squard_to_fill[row + y][col + x] );
				printf("ROW:: %i\n", row);
				printf("COL:: %i\n", col);

				printf("row + y: %i\n", row + y );
				printf("col + x: %i\n", col + x );
					
				if (squard_to_fill[row + y][col + x] != '.' || squard_to_fill[row + y][col + x] == '\0')
					return (0);

				if (is_it_first_time == 1)
				{
					if (catch_fig == 2)
					{
						x = x + 1;
						is_it_first_time = 0;
					}
					else if (catch_fig == 3)
					{
						x = x + 2;
						is_it_first_time = 0;
					}
					else if (catch_fig == 4)
					{
						x = x + 2;
						is_it_first_time = 0;
					}
				}
				// is_it_first_time = 0;

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
	char	sb_to_write;


sb_to_write = fig_counter + 'A';
	// sb_to_write = ft_itoa(fig_counter);
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
					if (f->matrix[0][1] == '#' && f->matrix[1][1] == '#' && f->matrix[2][0] == '#' && f->matrix[2][1] == '#'
					&& x == 3)
					{
						x = x - 1;
		
					}
					else if (f->matrix[0][2] == '#' && f->matrix[1][0] == '#' && f->matrix[1][1] == '#' && f->matrix[1][2] == '#'
						&& x == 3)
					{
						x = x - 2;
					}
					else if (f->matrix[0][2] == '#' && f->matrix[1][0] == '#' && f->matrix[1][1] == '#' && f->matrix[1][2] == '#'
						&& x == 4)
					{
						x = x - 2;
					}
				squard_to_fill[row + y][col + x] = sb_to_write;
			}
			col++;
		}
		row++;
	}
}

int		multiple_fit(char **squard_to_fill, figure *f,  int fig_counter, int squard_size)
{
	int		row;
	int		col;

	row = 0;
	printf("i'm in multiple_fit NOW!!! squard_size = %i \n", squard_size);
	while (row < squard_size)
	{
		col = 0;
		// printf("row: %i col: %i\n", row, col );
		while (col < squard_size)
		{
			printf("row: %i col: %i\n", row, col );
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
	int 	is_fit_result;

	printf("  Y: %i\n", f->y );
	printf("  X: %i\n", f->x );

	row = f->y;
	is_it_first_time = 1;
	is_fit_result = 0;

	printf("SQUARD_SIZE IN CAN_I_SHIFT IS: %i\n", squard_size );
	del_me(squard_to_fill, fig_counter, squard_size);
	// while (row <= (squard_size - f->y))
	while (row < squard_size)
	{
		// printf("row:: %i\n", row);
		printf("is_it_first_time:%i\n", is_it_first_time);
		if (is_it_first_time == 1)
		{
			if (f->x == squard_size - 1)
			{
				col = 0;
				row = row + 1;
				printf("i'm in if in can_i_shift ::row:: %i\n", row);
			}
			else
				col = f->x + 1;
			printf("%i\n", col);
		}
		else
			col = 0;

		if (squard_to_fill[row][col] == '\0')
		{
			printf("YESYES\n");
		}
		// while (col <= (squard_size - f->x))
		while (col < squard_size)
		{
				if (squard_to_fill[row][col] == '\0')
				{
					printf("YESYES\n");
					
				}

				printf("%c\n", squard_to_fill[row][col]);
				printf("ROW_BEFORE_IS_FIT:%i\n", row );
				printf("COL_BEFORE_IS_FIT:%i\n", col );
				is_fit_result = is_fit(f->matrix, squard_to_fill, row, col);
				printf("is_fit_result: %i\n", is_fit_result );
				if (is_fit_result == 1)
				{	
					f->x = col;
					f->y = row;

					// printf(" u can put here y %i\n", f->y );
					// printf(" u can put here x %i\n", f->x );
					printf("OKAY I FIND!!! row: %i col: %i\n", row, col );	
					return (1);
				}
			is_it_first_time = 0;
			printf("row: %i col: %i\n", row, col );
			col++;
		}
		is_it_first_time = 0;
		// printf("row: %i col: %i\n", row, col );
		row++;
	}
	return (0);
}
