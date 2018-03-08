/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:38:01 by kprytkov          #+#    #+#             */
/*   Updated: 2018/03/08 19:38:02 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		control_fn(int fig_number, char **squard_to_fill, int squard_size, figure **array_of_figures)
{
	int index;
	int logical;
	int counter;
	int m_f;

	index = 0;
	while (index < fig_number)
	{
		m_f = multiple_fit(squard_to_fill,
			array_of_figures[index], index, squard_size);
		if ((m_f == 0) && (is_full(squard_to_fill, squard_size) == 1))
		{
			free_me(squard_to_fill, squard_size);
			squard_size = squard_size + 1;
			squard_to_fill = ft_generate(squard_size);
			control_fn(fig_number, squard_to_fill,
				squard_size, array_of_figures);
			return (0);
		}
		else if (m_f == 0)
		{
			index = index - 1;
			where_is_xy(squard_to_fill,
				array_of_figures[index], index, squard_size);
			logical = can_i_shift(squard_to_fill,
				array_of_figures[index], index, squard_size);
			if (logical == 0)
			{
				counter = index;
				while (logical != 1 && counter > 0)
				{
					del_me(squard_to_fill, index, squard_size);
					index = index - 1;
					where_is_xy(squard_to_fill,
						array_of_figures[index], index, squard_size);
					logical = can_i_shift(squard_to_fill,
						array_of_figures[index], index, squard_size);
					counter--;
				}
				if (counter == 0 && (logical == 0))
				{
					free_me(squard_to_fill, squard_size);
					squard_size = squard_size + 1;
					squard_to_fill = ft_generate(squard_size);
					control_fn(fig_number, squard_to_fill,
						squard_size, array_of_figures);
					return (0);
				}
				index = counter;
				ok_here(squard_to_fill, array_of_figures[index],
					array_of_figures[index]->y,
					array_of_figures[index]->x, index);
			}
			else if (logical == 1)
				ok_here(squard_to_fill, array_of_figures[index],
					array_of_figures[index]->y,
					array_of_figures[index]->x, index);
		}
		index++;
	}
	print_squard(squard_to_fill, squard_size);
	return (1);
}

// Norme: ./control_function.c
// Error (line 15): function control_fn has 62 lines
// Error (line 15): line has 102 characters
