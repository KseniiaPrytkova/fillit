/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:06:06 by kprytkov          #+#    #+#             */
/*   Updated: 2018/03/08 20:06:07 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_sq_width(char **matrix)
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
				width++;
			col++;
		}
		if (width > max_width)
			max_width = width;
		row++;
	}
	if ((matrix[0][0] != '.' && matrix[0][1] != '.'
			&& matrix[1][1] != '.' && matrix[1][2] != '.')
			|| (matrix[0][1] != '.' && matrix[0][2] != '.'
			&& matrix[1][0] != '.' && matrix[1][1] != '.'))
		max_width++;
	return (max_width);
}

int		min_sq_height(char **matrix)
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
				height++;
			row++;
		}
		if (height > max_height)
			max_height = height;
		col++;
	}
	if ((matrix[0][1] != '.' && matrix[1][0] != '.'
				&& matrix[1][1] != '.' && matrix[2][0] != '.')
				|| (matrix[0][0] != '.' && matrix[1][0] != '.'
				&& matrix[1][1] != '.' && matrix[2][1] != '.'))
		max_height++;
	return (max_height);
}

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

void	free_me(char **squard_to_free, int squard_size)
{
	int		i;

	i = 0;
	while (i < squard_size + 2)
	{
		free(squard_to_free[i]);
		squard_to_free[i] = NULL;
		i++;
	}
	free(squard_to_free);
}

void	print_squard(char **squard, int squard_size)
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
		if (letter_index == squard_size)
		{
			letter_index = 0;
			ft_putchar('\n');
			row_index++;
		}
		counter++;
	}
}

// Norme: ./ft_generate.c
// Error (line 15): function min_sq_width has 28 lines
// Error (line 47): function min_sq_height has 28 lines