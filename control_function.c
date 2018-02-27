#include "fillit.h"

int control_fn(int fig_number, char **squard_to_fill, int squard_size, figure **array_of_figures )
{
	int index;
	int logical;
	int counter;

	index = 0;
	while (index < fig_number)
	{
		if (multiple_fit(squard_to_fill, array_of_figures[index], index, squard_size) == 1)
		{
			printf("The squard after putting  %i figure \n", index );
			print_squard(squard_to_fill, squard_size);
			printf("now index = %i\n", index );

		}
		else if ((multiple_fit(squard_to_fill, array_of_figures[index], index, squard_size)) == 0 && (is_full(squard_to_fill, squard_size) == 1) && (index > 1))
		{

			printf("i am full!!! Lets make the squard bigger!!!\n");
			free_me(squard_to_fill, squard_size);
					squard_size = squard_size + 1;
  					squard_to_fill = ft_generate(squard_size);
 					printf("RESULT FIELD + 1:\n");
 					print_squard(squard_to_fill, squard_size);
 					printf("control_fn says: %i\n", control_fn(fig_number, squard_to_fill, squard_size, array_of_figures ) );			
 					return (0);

			// while (1)
			// 	{};
		}
		else if (multiple_fit(squard_to_fill, array_of_figures[index], index, squard_size) == 0)
		{
			index = index - 1;
			where_is_xy(squard_to_fill, array_of_figures[index], index, squard_size);
			printf("x of figure %i = %i\n", index, array_of_figures[index]->x);
			printf("y of figure %i = %i\n", index, array_of_figures[index]->y);
			printf("CAN_I_SHIFT START WORKING!!!--------->>>>>>>>>\n");
			logical = can_i_shift(squard_to_fill, array_of_figures[index], index, squard_size);
			print_squard(squard_to_fill, squard_size);
			printf("i am logical of can_i_shift on fig %i : %i\n", index, logical);
			if (logical == 0)
			{
				counter = index;
				while (logical != 1 && counter > 0)
				{
					printf("I can't shift =(\n");
					del_me(squard_to_fill, index, squard_size);

					index = index - 1;
					print_squard(squard_to_fill, squard_size);
					printf("now index = %i\n", index );
					printf("we should shift figure %i \n", index);

					where_is_xy(squard_to_fill, array_of_figures[index], index, squard_size);
					printf("x of figure %i = %i\n", index, array_of_figures[index]->x);
					printf("y of figure %i = %i\n", index, array_of_figures[index]->y);
					logical = can_i_shift(squard_to_fill, array_of_figures[index], index, squard_size);

					counter--;
				}

				if (counter == 0 && (can_i_shift(squard_to_fill, array_of_figures[index], index, squard_size) == 0) )
				{
					printf("WE MUST MAKE THE SQUARD BIGGER!!!\n");
					print_squard(squard_to_fill, squard_size);
					ft_putchar('\n');

					free_me(squard_to_fill, squard_size);
					squard_size = squard_size + 1;
  					squard_to_fill = ft_generate(squard_size);
 					printf("RESULT FIELD + 1:\n");
 					print_squard(squard_to_fill, squard_size);
 					printf("control_fn says: %i\n", control_fn(fig_number, squard_to_fill, squard_size, array_of_figures ) );			
 					return (0);
				}

				index = counter;

				printf("so now I CAN shift :D\n");
				printf("index = %i\n", index );

				printf(" u can put y here: %i\n", array_of_figures[index]->y);
				printf(" u can put x here: %i\n", array_of_figures[index]->x);
				ok_here(squard_to_fill, array_of_figures[index], array_of_figures[index]->y, array_of_figures[index]->x, index);
			
				print_squard(squard_to_fill, squard_size);
				ft_putchar('\n');
			
			}
			else if (logical == 1)
			{
				print_squard(squard_to_fill, squard_size);
				printf("I CAN shift(logical = 1) :D\n");
				printf("index = %i\n", index );

				printf(" u can put y here: %i\n", array_of_figures[index]->y);
				printf(" u can put x here: %i\n", array_of_figures[index]->x);

				// can_i_shift(squard_to_fill, array_of_figures[index], index, squard_size);
				// printf(" u can put y here: %i\n", array_of_figures[index]->y);
				// printf(" u can put x here: %i\n", array_of_figures[index]->x);
				// print_squard(squard_to_fill, squard_size);
				ok_here(squard_to_fill, array_of_figures[index], array_of_figures[index]->y, array_of_figures[index]->x, index);
			
				print_squard(squard_to_fill, squard_size);
				ft_putchar('\n');
				printf("we shifted %i figure\n", index );
			}

		}

			index++;
			printf(">>>>>INDEX<<<<< = %i\n", index );
	}
	return(1);
		
} 
