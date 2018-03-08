#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 21:53:35 by kprytkov          #+#    #+#              #
#    Updated: 2018/03/08 21:53:37 by kprytkov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
HEADER = fillit.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = algorithm_helpers.c control_function.c figure_offset.c is_fit.c fillit.c \
	ft_checktabl.c ft_generate.c read_from_file.c
OBJ = algorithm_helpers.o control_function.o figure_offset.o is_fit.o fillit.o \
	ft_checktabl.o ft_generate.o read_from_file.o
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) $(OPTION) $(SRC)
	gcc -o $(NAME) $(LIB) $(OBJ)

clean:
	make clean -C libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all

# CHECKING RULE: fclean
# -> Failing rule: It should have cleaned the libraries