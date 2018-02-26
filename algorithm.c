/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:37:25 by kprytkov          #+#    #+#             */
/*   Updated: 2018/01/17 16:37:26 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// void	put_fig(char **fill_me, char **matrix, int fig_nb, int squard_size)
// {
// 	int limit;
// 	int counter;
// 	int ft_index;
// 	int sd_index;

// 	limit = squard_size * squard_size;
// 	counter = 0;
// 	ft_index = 0;
// 	sd_index = 0;
	

// 	while (counter < limit)
// 	{
// 		fill_me[ft_index][sd_index] = matrix[ft_index][sd_index];
// 		sd_index++;

// 		if (sd_index == squard_size)
// 		{
// 			sd_index = 0;
// 			ft_index++;

// 		}
// 		counter++;
// 	}

// }

void	del_me(char **squard_to_fill, int nb_of_fig_to_del)
{
	int		row;
	int		col;
	char	*sb_to_be_found;


	row = 0;
	sb_to_be_found = ft_itoa(nb_of_fig_to_del);
	// printf("%s\n", sb_to_be_found );
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (squard_to_fill[row][col] == *sb_to_be_found)
			{
				squard_to_fill[row][col] = '.';
			}
			col++;
		}
		row++;
	}
}

// int		should_extend(int	*states, int	index)
// {
// 	int i;

// 	i = 0;
// 	while (i < index)
// 	{
// 		if (states[i] == 0)
// 		{
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// void	shift_me(char **squard_to_fill, squard_size)
// {
// 	move_shape(squard_to_fill, -1, -1, squard_size);
// }

// int		where_is_x(char **squard_to_fill, int	fig_counter)
// {
// 	int		row;
// 	int		col;
// 	char	*sb_to_look_for;
// 	int		current_x;

// 	sb_to_look_for = ft_itoa(fig_counter);
// 	row = 0;
// 	while (row < 4)
// 	{
// 		col = 0;
// 		while (col < 4)
// 		{
// 			if (squard_to_fill[row][col] == *sb_to_look_for)
// 			{
// 				current_x = col;
// 				break;
// 			}
// 			col++;
// 		}
// 		row++;
// 	}
// 	return (current_x);
// }

// int		where_is_y(char **squard_to_fill, int	fig_counter)
// {
// 	int		row;
// 	int		col;
// 	char	*sb_to_look_for;
// 	int		current_y;

// 	sb_to_look_for = ft_itoa(fig_counter);
// 	row = 0;
// 	while (row < 4)
// 	{
// 		col = 0;
// 		while (col < 4)
// 		{
// 			if (squard_to_fill[row][col] == *sb_to_look_for)
// 			{
// 				current_y = row;
// 				break;
// 			}
// 			col++;
// 		}
// 		row++;
// 	}
// 	return (current_y);
// }

int		where_is_xy(char **squard_to_fill, figure *f, int	fig_counter)
{
	int		row;
	int		col;
	char	*sb_to_look_for;


	sb_to_look_for = ft_itoa(fig_counter);
	// printf("%s\n", sb_to_look_for );
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (squard_to_fill[row][col] == *sb_to_look_for)
			{
				f->x = col;
				// printf("x is: %i\n", col );
				f->y = row;
				// printf("y is: %i\n", row );
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

// int 	increment_coordinates(figure *f, char **squard_to_fill)
// {
// 	if ()
// }

// qqq
