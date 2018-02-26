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

int 	get_x_offset(char **matrix)
{
	int	row;
	int letter;
	int offset;

	row = 0;
	offset = 4 - 1;

	while (row < 4)
	{
		letter = 0;
		while (letter < 4)
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

int 	get_y_offset(char **matrix)
{
	int row;
	int letter;
	int offset;

	letter = 0;
	offset = 4 - 1;

	while (letter < 4)
	{
		row = 0;
		while (row < 4)
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

void 	clean_matrix(char **matrix)
{
	int row;
	int letter;

	row = 0;
	while (row < 4)
	{
		letter = 0;
		while (letter < 4)
		{
			matrix[row][letter] = '.';
			letter++;
		}
		row++;
	}
}

void move_shape(char **matrix, int get_x_offset, int get_y_offset)
{
	char temp[4][4];
	int row;
	int letter;


	row = 0;
	while (row < 4)
	{
		letter = 0;
		while(letter < 4)
		{
			temp[row][letter] = matrix[row][letter];
			letter++;
		}
		row++;
	}

	clean_matrix(matrix);
	row = 0;
	while (row < 4)
	{
		letter = 0;
		while (letter < 4)
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

void figure_offset(char **matrix)
{
	int x_offset;
	int y_offset;

	x_offset = get_x_offset(matrix);
	y_offset = get_y_offset(matrix);
	if (x_offset || y_offset)
		move_shape(matrix, x_offset, y_offset);
}

