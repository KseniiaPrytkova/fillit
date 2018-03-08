/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:27:52 by kprytkov          #+#    #+#             */
/*   Updated: 2018/03/08 20:27:53 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_fit(char **matrix, char **squard_to_fill, int y, int x)
{
	int		row;
	int		col;
	int		is_it_first_time;
	int		catch_fig;

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
					x = x - 1;
					catch_fig = 2;
				}
				else if (matrix[0][2] == '#' && matrix[1][0] == '#' && matrix[1][1] == '#' && matrix[1][2] == '#'
						&& x == 3)
				{
					x = x - 2;
					catch_fig = 3;
				}
				else if (matrix[0][2] == '#' && matrix[1][0] == '#' && matrix[1][1] == '#' && matrix[1][2] == '#'
						&& x == 4)
				{
					x = x - 2;
					catch_fig = 4;
				}
				else
					is_it_first_time = 0;
			}
			if (matrix[row][col] == '#' || (matrix[row][col] > '0'
				&& matrix[row][col] <= '9') || (matrix[row][col] > 'A' && matrix[row][col] <= 'Z'))
			{
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
			}
			col++;
		}
		row++;
	}
	return (1);
}

void		ok_here(char **squard_to_fill, figure *f, int y, int x, int fig_counter)
{
	int		row;
	int		col;
	char	sb_to_write;

	sb_to_write = fig_counter + 'A';
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
					x = x - 1;
				else if (f->matrix[0][2] == '#' && f->matrix[1][0] == '#' && f->matrix[1][1] == '#' && f->matrix[1][2] == '#'
						&& x == 3)
					x = x - 2;
				else if (f->matrix[0][2] == '#' && f->matrix[1][0] == '#' && f->matrix[1][1] == '#' && f->matrix[1][2] == '#'
						&& x == 4)
					x = x - 2;
				squard_to_fill[row + y][col + x] = sb_to_write;
			}
			col++;
		}
		row++;
	}
}

int			multiple_fit(char **squard_to_fill, figure *f, int fig_counter, int squard_size)
{
	int		row;
	int		col;

	row = 0;
	while (row < squard_size)
	{
		col = 0;
		while (col < squard_size)
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

int			can_i_shift(char **squard_to_fill, figure *f, int fig_counter, int squard_size)
{
	int		row;
	int		col;
	int		is_it_first_time;

	row = f->y;
	is_it_first_time = 1;
	del_me(squard_to_fill, fig_counter, squard_size);
	while (row < squard_size)
	{
		if (is_it_first_time == 1)
		{
			if (f->x == squard_size - 1)
			{
				col = 0;
				row = row + 1;
			}
			else
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
				return (1);
			}
			is_it_first_time = 0;
			col++;
		}
		row++;
	}
	return (0);
}

// Norme: ./is_fit.c
// Error (line 15): function is_fit has 65 lines
// Error (line 32): line has 109 characters
// Error (line 38): line has 114 characters
// Error (line 44): line has 114 characters
// Error (line 54): line has 100 characters
// Error (line 56): line has 105 characters
// Error (line 84): ok_here have 5 parameters
// Error (line 84): function ok_here has 30 lines
// Error (line 84): line has 85 characters
// Error (line 101): line has 121 characters
// Error (line 104): line has 126 characters
// Error (line 107): line has 126 characters
// Error (line 118): line has 93 characters
// Error (line 141): function can_i_shift has 35 lines
// Error (line 141): line has 92 characters

