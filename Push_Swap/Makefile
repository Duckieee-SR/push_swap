# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 15:45:03 by gamaro-l          #+#    #+#              #
#    Updated: 2023/06/29 14:19:14 by gamaro-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	push_swap.a

SRC=	2int_3int.c\
		4int.c\
		5int.c\
		algorithm.c\
		chunks.c\
		exit.c\
		extra_functions.c\
		push_swap.c\
		utils_a.c\
		utils_b.c

OBJ=	$(subst .c,.o,$(SRC))

CC=		gcc
CFLAGS=	-g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)

%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f ./a.out $(NAME)

re: fclean all

.PHONY: all clean fclean re
