#include "fillit.h"

int		ft_squard_size(int fig_number)
{
	int		i;

	i = 2;
	while (i * i < fig_number * 4)
		i++;
	return (i);
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
	
	i = 0;
	while (i < squard_size + 2)
	{
		free(squard_to_free[i]);
	}
	free(squard_to_free);
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
