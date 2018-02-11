/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_offset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:36:54 by kprytkov          #+#    #+#             */
/*   Updated: 2018/01/17 16:37:03 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	get_x_offset(char **matrix, int squard_size)
{
	int	row;
	int letter;
	int offset;

	row = 0;
	offset = squard_size - 1;

	while (row < squard_size)
	{
		letter = 0;
		while (letter < squard_size)
		{
			if (matrix[row][letter] != '.')
			{
				if (letter < offset)
					offset = letter;
			}
			letter++;
		}
		row++;
	}
	return (offset);
}

int 	get_y_offset(char **matrix, int squard_size)
{
	int row;
	int letter;
	int offset;

	letter = 0;
	offset = squard_size - 1;

	while (letter < squard_size)
	{
		row = 0;
		while (row < squard_size)
		{
			if (matrix[row][letter] != '.')
			{
				if (row < offset)
					offset = row;
			}
			row++;
		}
		letter++;
	}
	return (offset);
}

void 	clean_matrix(char **matrix, int squard_size)
{
	int row;
	int letter;

	row = 0;
	while (row < squard_size)
	{
		letter = 0;
		while (letter < squard_size)
		{
			matrix[row][letter] = '.';
			letter++;
		}
		row++;
	}
}

void move_shape(char **matrix, int get_x_offset, int get_y_offset, int squard_size)
{
	char temp[4][4];
	int row;
	int letter;


	row = 0;
	while (row < squard_size)
	{
		letter = 0;
		while(letter < squard_size)
		{
			temp[row][letter] = matrix[row][letter];
			letter++;
		}
		row++;
	}

	clean_matrix(matrix, squard_size);
	row = 0;
	while (row < squard_size)
	{
		letter = 0;
		while (letter < squard_size)
		{
			if (temp[row][letter] != '.')
			{
				matrix[row - get_y_offset][letter - get_x_offset] = temp[row][letter];
			}
			letter++;
		}
		row++;
	}

}

void figure_offset(char **matrix, int squard_size)
{
	int x_offset;
	int y_offset;

	x_offset = get_x_offset(matrix, squard_size);
	y_offset = get_y_offset(matrix, squard_size);
	if (x_offset || y_offset)
		move_shape(matrix, x_offset, y_offset, squard_size);
}

