#include "fillit.h"

// int		ft_squard_size(int fig_number)
// {
// 	int		i;

// 	i = 2;
// 	while (i * i < fig_number * 4)
// 		i++;
// 	return (i);
// }

int 	min_sq_width(char **matrix)
{
	int row;
	int col;
	int	width;
	int max_width;

	row = 0;
	width = 0;
	max_width = 0;

	while (row < 4)
	{
		col = 0;
		width = 0;
		while (col < 4)
		{
			if (matrix[row][col] != '.')
			{
				width++;
			}
			col++;
		}
		if (width > max_width)
		{
			max_width = width;
		}
		row++;
	}
	if ( (matrix[0][0] != '.' && matrix[0][1] != '.' && matrix[1][1] != '.' && matrix[1][2] != '.') ||
	 	(matrix[0][1] != '.' && matrix[0][2] != '.' && matrix[1][0] != '.' && matrix[1][1] != '.'))
		{
			max_width++;
		}
	return(max_width);
}

int 	min_sq_height(char **matrix)
{
	int row;
	int col;
	int height;
	int max_height;

	col = 0;

		height = 0;

	max_height = 0;

	while (col < 4)
	{
		row = 0;
		height = 0;
		while (row < 4)
		{
			if (matrix[row][col] != '.')
			{
				height++;
			}
			row++;
		}
		printf("%i\n", height );
		if (height > max_height)
		{
			max_height = height;
		}
		printf("max: %i\n", max_height );
		col++;
	}
		if ((matrix[0][1] != '.' && matrix[1][0] != '.' && matrix[1][1] != '.' && matrix[2][0] != '.') ||
			(matrix[0][0] != '.' && matrix[1][0] != '.' && matrix[1][1] != '.' && matrix[2][1] != '.'))
		{
			max_height++;
		}
	return(max_height);
}

// //создает массив с квадратом, заполняет точками и ставить в конце каждой строки \0
char	**ft_generate(int squard_size)
{
	char	**squard;
	int		i;
	int		j;

	i = 0;
	if (!(squard = (char **)malloc(sizeof(char *) * (squard_size + 2))))
		return (NULL);
	while (i < squard_size + 2)
	{
		j = 0;
		if (!(squard[i] = (char *)malloc(sizeof(char) * (squard_size + 2))))
			return (NULL);
		while (j < squard_size + 2)
		{
			if (i >= squard_size || j >= squard_size)
				squard[i][j] = '\0';
			else 
				squard[i][j] = '.';
			j++;
		}
		i++;
	}
	return (squard);
}

void 	free_me(char **squard_to_free, int	squard_size)
{
	int		i;
	print_squard(squard_to_free, squard_size);

	i = 0;
			// system("leaks test");
	while (i < squard_size + 2)
	{
		free(squard_to_free[i]);
		squard_to_free[i] = NULL;
		i++;
		printf("%i\n", i );
	}
	free(squard_to_free);
	printf("%p\n", squard_to_free);
	printf("now i'm here!!!\n");
	// print_squard(squard_to_free, squard_size);
	// squard_to_free = NULL;
	printf("%p\n", squard_to_free);
}

void 	print_squard(char **squard, int squard_size)
{
	int limit;
	int counter;
	int	letter_index;
	int row_index;

	limit = squard_size * squard_size;
	counter = 0;
	letter_index = 0;
	row_index = 0;
	while (counter < limit)
	{
		ft_putchar(squard[row_index][letter_index]);
		letter_index++;
		if(letter_index == squard_size)
		{
			letter_index = 0;
			ft_putchar('\n');
			row_index++;
		}
		counter++;
	}
}
