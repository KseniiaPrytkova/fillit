/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 22:20:32 by kprytkov          #+#    #+#             */
/*   Updated: 2018/03/08 22:20:36 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_me(char **squard_to_fill, int nb_of_fig_to_del, int squard_size)
{
	int		row;
	int		col;
	char	sb_to_be_found;

	sb_to_be_found = nb_of_fig_to_del + 'A';
	row = 0;
	while (row < squard_size)
	{
		col = 0;
		while (col < squard_size)
		{
			if (squard_to_fill[row][col] == sb_to_be_found)
			{
				squard_to_fill[row][col] = '.';
			}
			col++;
		}
		row++;
	}
}

int		where_is_xy(char **squard_to_fill, figure *f, int fig_counter, int squard_size)
{
	int		row;
	int		col;
	char	sb_to_look_for;

	sb_to_look_for = fig_counter + 'A';
	row = 0;
	while (row < squard_size)
	{
		col = 0;
		while (col < squard_size)
		{
			if (squard_to_fill[row][col] == sb_to_look_for)
			{
				f->x = col;
				f->y = row;
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int		is_full(char **squard_to_fill, int squard_size)
{
	int		row;
	int		col;
	int		not_full;

	row = 0;
	not_full = 0;
	while (row < squard_size)
	{
		col = 0;
		while (col < squard_size)
		{
			if (squard_to_fill[row][col] == '.')
				not_full++;
			col++;
		}
		row++;
	}
	if (not_full == 0)
		return (1);
	return (0);
}

// Norme: ./algorithm.c
// Error (line 38): line has 88 characters
