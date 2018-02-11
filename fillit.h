/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:39:05 by kprytkov          #+#    #+#             */
/*   Updated: 2018/01/17 16:39:06 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct	shape	
{
	char 			**matrix;
}				figure;

char				*read_from_file(char *filename);
int					ft_checktabl(char *str);
int					ft_squard_size(int fig_number);
char				**ft_generate(int squad_size);
void 				print_squard(char **squard, int squard_size);
void	put_fig(char **fill_me, char **array_of_fig, int fig_nb, int squard_size);
int 	get_x_offset(char **matrix, int squard_size);
int 	get_y_offset(char **matrix, int squard_size);
void 	clean_matrix(char **matrix, int squard_size);
void move_shape(char **matrix, int get_x_offset, int get_y_offset, int squard_size);
void figure_offset(char **matrix, int squard_size);

#endif
