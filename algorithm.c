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

void	put_fig(char **fill_me, char **matrix, int fig_nb, int squard_size)
{
	int limit;
	int counter;
	int ft_index;
	int sd_index;

	limit = squard_size * squard_size;
	counter = 0;
	ft_index = 0;
	sd_index = 0;
	

	while (counter < limit)
	{
		fill_me[ft_index][sd_index] = matrix[ft_index][sd_index];
		sd_index++;

		if (sd_index == squard_size)
		{
			sd_index = 0;
			ft_index++;

		}
		counter++;
	}

}




