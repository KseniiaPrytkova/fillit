/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:39:45 by kprytkov          #+#    #+#             */
/*   Updated: 2018/01/17 16:39:46 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUF_SIZE 547

char	*read_from_file(char *filename)
{
	int		fd;
	int		ret;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (NULL);
	}
	if (!(buffer = malloc(sizeof(char) * BUF_SIZE + 1)))
		return (NULL);
	ret = read(fd, buffer, BUF_SIZE);
	buffer[ret] = '\0';
	// ft_putnbr(ret);
	// ft_putchar('\n');
	// ft_putstr(buffer);
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (NULL);
	}
	return (buffer);
}

