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

//VERSION 13.02
#include "fillit.h"


//creating an array of pointers
//NOT the same with two-dimensional array
//!!!
figure 	*init_figure()
{
	//variable f has type figure
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

void print_figure(figure *f)
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
	char	*file_name;
	char	*result_string;
	figure	*empty_figure;
	int 	fig_number;
	int 	index;
	char	**squard_to_fill;
	int 	squard_size;
	int 	*states;
	int logical;


	figure **array_of_figures;

	if (argc == 2)
	{
		file_name = argv[1];
	}

	result_string = read_from_file(file_name);	
	fig_number = ft_checktabl(result_string);
	if (fig_number == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	printf("There is %i figures in file! \n", fig_number);
	array_of_figures = malloc(sizeof(figure *) * fig_number);
	//тут будут проверочки
	index = 0;
	while (index < fig_number)
	{
		empty_figure = init_figure();
		figure_copy_paste(empty_figure, result_string);
		array_of_figures[index] = empty_figure;
		// print_figure(array_of_figures[index]);
		// ft_putchar('\n');
		index++;
		result_string = result_string + 21;
	}

	squard_size = ft_squard_size(fig_number);
	// printf("Squard_size is: %i\n", squard_size );
// также работаем с array_of_figures но все фигуры смещены в левый верхний угол с помощью
// функции figure_offset. т.е каждый matrix был перезаписан и смещен в угол
	index = 0;
	while (index < fig_number)
	{
		figure_offset(array_of_figures[index]->matrix, squard_size);
		print_squard(array_of_figures[index]->matrix, squard_size);
		ft_putchar('\n');
		index++;
	}
	// printf("x_offset is %i\n", get_x_offset(array_of_figures[2]->matrix, squard_size));
	// printf("y_offset is %i\n", get_y_offset(array_of_figures[2]->matrix, squard_size));

	squard_to_fill = ft_generate(squard_size);
 	
	// пустой. сюда будем вставлять фигуры
	// printf("This is squard to fill! must be empty!\n");
	// print_squard(squard_to_fill, squard_size);
	printf("-----------------\n");

// В НАШЕ ПУСТОЕ РАБОЧЕЕ ПОЛЕ (squard_to_fill) ЗАПИСЫВАЕМ 1Ю ФИГУРУ!!!
	// ok_here(squard_to_fill, array_of_figures[0], 0, 0, 0);

	printf("RESULT FIELD:\n");
	print_squard(squard_to_fill, squard_size);


	// squard_size = squard_size + 1;
	// squard_to_fill = ft_generate(squard_size);
	// printf("RESULT FIELD + 1:\n");
	// print_squard(squard_to_fill, squard_size);
	// printf("is fit? %i \n", is_fit(array_of_figures[1]->matrix, squard_to_fill, 3, 3));

	// index = 0 it's the very 1st figure, skip it!!!
	// index = 0;
	// while (index < 3)
	// {
	// 	if (multiple_fit(squard_to_fill, array_of_figures[index], index)) {
	// 		index++;
	// 	}
	// 	else
	// 	{
	// 		index--;
	// 		del_me(squard_to_fill, index);
			
	// 		if (can_i_shift(squard_to_fill, array_of_figures[index], index)) {
	// 			printf("Shifted\n");
	// 		} else {
	// 			printf("NOT Shifted %i\n", index);
	// 			// del_me(squard_to_fill, index - 1);
	// 			index--;
	// 		}
	// 	}
	// 		printf("AFTER PUTTING NEXT FIGURE:\n");
	// 		print_squard(squard_to_fill, squard_size);
	// }
		// multi_fit(squard_to_fill, array_of_figures[1]->matrix);


	// states = malloc(sizeof(int) * fig_number);
	// index = 0;
	// while (index < fig_number)
	// {
	// 	if (can_i_shift(squard_to_fill, array_of_figures[index], index))
	// 	{
	// 		printf("Shifted: %i\n", index);
	// 		states[index] = 0;
	// 		index++;
	// 	}
	// 	else
	// 	{
	// 		states[index] = 1;
	// 		printf("NOT Shifted: %i\n", index);
	// 		if (should_extend(states, index) == 1)
	// 		{
	// 			//extend squard
	// 			free_me(squard_to_fill, squard_size);
	// 			squard_size++;
	// 			squard_to_fill = ft_generate(squard_size);
	// 			index = 0;
	// 			continue;
	// 		}

	// 		index--;
	// 		array_of_figures[index]->x = -1;
	// 		array_of_figures[index]->y = 0;
			
	// 			// continue;
	// 	}
	// 		printf("AFTER PUTTING NEXT FIGURE:\n");
	// 		print_squard(squard_to_fill, squard_size);
	// }

	index = 0;

	if (multiple_fit(squard_to_fill, array_of_figures[index], index) == 1)
		index++;
	printf("AFTER PUTTING NEXT FIGURE:\n");
	print_squard(squard_to_fill, squard_size);
	printf("now index = %i\n", index );

	// index = 1;
	if (multiple_fit(squard_to_fill, array_of_figures[index], index) == 1)
		index++;
	printf("AFTER PUTTING NEXT FIGURE:\n");
	print_squard(squard_to_fill, squard_size);
	printf("now index = %i\n", index );

	// index = 2;
	if (multiple_fit(squard_to_fill, array_of_figures[index], index) == 1)
	{
		index++;
		printf("AFTER PUTTING NEXT FIGURE:\n");
		print_squard(squard_to_fill, squard_size);
		printf("now index = %i\n", index );
	}
	else
	{

		index = index - 1;
		// index = 1;

		where_is_xy(squard_to_fill, array_of_figures[index], index);
		printf("x = %i\n", array_of_figures[index]->x  );
		printf("y = %i\n", array_of_figures[index]->y  );

		// printf("can shift? %i\n", can_i_shift(squard_to_fill, array_of_figures[index - 1],  index - 1) );
		if (can_i_shift(squard_to_fill, array_of_figures[index],  index) == 0)
		{
			del_me(squard_to_fill, index);

			index = index - 1;
			// index = 0;

			print_squard(squard_to_fill, squard_size);
			printf("now index = %i\n", index );
			printf(">>figure %i ++ \n", index );

			where_is_xy(squard_to_fill, array_of_figures[0], 0);
			printf("x = %i\n", array_of_figures[0]->x  );
			printf("y = %i\n", array_of_figures[0]->y  );

		}
		if (can_i_shift(squard_to_fill, array_of_figures[index],  index) == 1)
		{
					printf(" u can put here y %i\n", array_of_figures[0]->y);
					printf(" u can put here x %i\n", array_of_figures[0]->x);
			ok_here(squard_to_fill, array_of_figures[index], array_of_figures[0]->y, array_of_figures[0]->x, index);
			index = index + 1;
			print_squard(squard_to_fill, squard_size);
			ft_putchar('\n');
		}

		if (multiple_fit(squard_to_fill, array_of_figures[index], index) == 1)
		index++;
		print_squard(squard_to_fill, squard_size);
		printf("now index = %i\n", index );
/////////////
		
		if (multiple_fit(squard_to_fill, array_of_figures[index], index) == 0)
		{
			index--;
			where_is_xy(squard_to_fill, array_of_figures[index], index);
			printf("x = %i\n", array_of_figures[index]->x  );
			printf("y = %i\n", array_of_figures[index]->y  );

		 	if (can_i_shift(squard_to_fill, array_of_figures[index],  index) == 0)
			{
				del_me(squard_to_fill, index);

				index = index - 1;
			// index = 0;

				print_squard(squard_to_fill, squard_size);
				printf("now index = %i\n", index );
				printf(">>figure %i ++ \n", index );

				where_is_xy(squard_to_fill, array_of_figures[0], 0);
				printf("x = %i\n", array_of_figures[0]->x  );
				printf("y = %i\n", array_of_figures[0]->y  );

			}
			if (can_i_shift(squard_to_fill, array_of_figures[index],  index) == 1)
			{
					printf(" u can put here y %i\n", array_of_figures[0]->y);
					printf(" u can put here x %i\n", array_of_figures[0]->x);
			ok_here(squard_to_fill, array_of_figures[index], array_of_figures[0]->y, array_of_figures[0]->x, index);
			index = index + 1;
			print_squard(squard_to_fill, squard_size);
			ft_putchar('\n');
			}

		}

		if (multiple_fit(squard_to_fill, array_of_figures[index], index) == 1)
		index++;
		print_squard(squard_to_fill, squard_size);
		printf("now index = %i\n", index );

		if (multiple_fit(squard_to_fill, array_of_figures[index], index) == 1)
		index++;
		print_squard(squard_to_fill, squard_size);
		printf("now index = %i\n", index );

// index = 3;
		printf("--------------------\n");

		if (multiple_fit(squard_to_fill, array_of_figures[index], index) == 0)
		{
			index--;
			where_is_xy(squard_to_fill, array_of_figures[index], index);
			printf("x = %i\n", array_of_figures[index]->x  );
			printf("y = %i\n", array_of_figures[index]->y  );

		}
printf("i am here\n");
logical = can_i_shift(squard_to_fill, array_of_figures[index],  index);
printf("i am logical:%i\n", logical);

		if (logical == 0)
		{
				printf("i can't shift\n");
				del_me(squard_to_fill, index);

				index = index - 1;
			// index = 0;

				print_squard(squard_to_fill, squard_size);
				printf("now index = %i\n", index );
				printf(">>figure %i ++ \n", index );

				where_is_xy(squard_to_fill, array_of_figures[0], 0);
				printf("x = %i\n", array_of_figures[0]->x  );
				printf("y = %i\n", array_of_figures[0]->y  );

		}
		else if (logical == 1)
		{
			printf("i CAN shift\n");
					printf(" u can put here y %i\n", array_of_figures[index]->y);
					printf(" u can put here x %i\n", array_of_figures[index]->x);
			ok_here(squard_to_fill, array_of_figures[index], array_of_figures[index]->y, array_of_figures[index]->x, index);
			index = index + 1;
			print_squard(squard_to_fill, squard_size);
			ft_putchar('\n');
		}
		
			if (multiple_fit(squard_to_fill, array_of_figures[index], index) == 1)
		index++;
		print_squard(squard_to_fill, squard_size);
		printf("now index = %i\n", index );


	}



	return (0);
}
