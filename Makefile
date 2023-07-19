# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 15:56:56 by knabeel           #+#    #+#              #
#    Updated: 2023/06/20 16:30:58 by knabeel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME            =   push_swap

SRC				=	main.c utils.c ft_list.c index.c commands.c ft_sorting.c radix.c utils2.c utils3.c utils4.c commands2.c commands3.c

OBJ = $(SRC:.c=.o)

CC				=	gcc
RM 				=	rm -rf
CFLAGS			= 	-Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all fclean re