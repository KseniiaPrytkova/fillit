/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:37:53 by kprytkov          #+#    #+#             */
/*   Updated: 2018/01/17 16:37:55 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

figure	*init_figure(void)
{
	figure *f;

	if (!(f = malloc(sizeof(figure))))
		return (NULL);
	if (!(f->matrix = malloc(sizeof(char *) * 4)))
		return (NULL);
	f->matrix[0] = ft_strnew(4 + 1);
	f->matrix[1] = ft_strnew(4 + 1);
	f->matrix[2] = ft_strnew(4 + 1);
	f->matrix[3] = ft_strnew(4 + 1);
	f->x = -1;
	f->y = 0;
	return (f);
}

void	figure_copy_paste(figure *empty, char *str)
{
	int	counter;
	int	letter_index;
	int row_index;

	counter = 0;
	letter_index = 0;
	row_index = 0;
	while (counter < 16)
	{
		empty->matrix[row_index][letter_index] = *str;
		letter_index++;
		if (letter_index == 4)
		{
			letter_index = 0;
			row_index++;
			str++;
		}
		str++;
		counter++;
	}
}

void	print_figure(figure *f)
{
	int	counter;
	int	letter_index;
	int row_index;

	counter = 0;
	letter_index = 0;
	row_index = 0;
	while (counter < 16)
	{
		ft_putchar(f->matrix[row_index][letter_index]);
		letter_index++;
		if (letter_index == 4)
		{
			letter_index = 0;
			ft_putchar('\n');
			row_index++;
		}
		counter++;
	}
}

int		main(int argc, char *argv[])
{
	char	*file_name = NULL;
	char	*result_string;
	figure	*empty_figure;
	int	fig_number;
	int	index;
	char	**squard_to_fill;
	int	squard_size;
	figure	**array_of_figures;

	if (argc == 2)
		file_name = argv[1];
	else
		printf("it will be USAGE here\n");
	result_string = read_from_file(file_name);
	fig_number = ft_checktabl(result_string);
	if (fig_number == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	array_of_figures = malloc(sizeof(figure *) * fig_number);
	index = 0;
	while (index < fig_number)
	{
		empty_figure = init_figure();
		figure_copy_paste(empty_figure, result_string);
		array_of_figures[index] = empty_figure;
		index++;
		result_string = result_string + 21;
	}
	index = 0;
	while (index < fig_number)
	{
		figure_offset(array_of_figures[index]->matrix);
		index++;
	}
	min_sq_width(array_of_figures[0]->matrix);
	min_sq_height(array_of_figures[0]->matrix);
	squard_size = min_sq_width(array_of_figures[0]->matrix);
	if (min_sq_height(array_of_figures[0]->matrix) > squard_size)
		squard_size = min_sq_height(array_of_figures[0]->matrix);
	squard_to_fill = ft_generate(squard_size);
	control_fn(fig_number, squard_to_fill, squard_size, array_of_figures);

	return (0);
}

// Norme: ./fillit.c
// Error (line 79): function main has 44 lines
// Error (line 79, col 0): main has 8 variables
// Error (line 81, col 7): file_name is instanciated during declaration
