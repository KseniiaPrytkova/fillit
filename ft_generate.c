/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:02:29 by evlasov           #+#    #+#             */
/*   Updated: 2018/01/14 21:02:31 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//считает сторону квадрата. Можно запхать в отдельный файл
int		ft_squard_size(int fig_number)
{
	int		i;

	i = 2;
	while (i * i < fig_number * 4)
		i++;
	return (i);
}

// //создает массив с квадратом, заполняет точками и ставить в конце каждой строки \0
char	**ft_generate(int squard_size)
{
	char	**squard;
	int		i;
	int		j;

	i = 0;
	if (!(squard = (char **)malloc(sizeof(char *) * (squard_size + 1))))
		return (NULL);
	while (i < squard_size)
	{
		j = 0;
		if (!(squard[i] = (char *)malloc(sizeof(char) * (squard_size + 1))))
			return (NULL);
		while (j < squard_size)
		{
			squard[i][j] = '.';
			j++;
		}
		squard[i][j] = '\0';
		i++;
	}
	return (squard);
}
void 	print_squard(char **squard, int squard_size)
{
	int limit;
	int counter;
	int	letter_index;
	int row_index;

	limit = squard_size * squard_size;
	counter = 0;
	letter_index = 0;
	row_index = 0;
	while (counter < limit)
	{
		ft_putchar(squard[row_index][letter_index]);
		letter_index++;
		if(letter_index == squard_size)
		{
			letter_index = 0;
			ft_putchar('\n');
			row_index++;
		}
		counter++;
	}
}
