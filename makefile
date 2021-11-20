# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 16:52:46 by dmonteir          #+#    #+#              #
#    Updated: 2021/11/20 18:59:46 by dmonteir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./includes/pipex.h

FILES =  main.c \
		./source/this_pipe.c \
		./utils/ft_bzero.c \

RM = rm -f
OBJS = $(FILES:.c=.o)

all:	$(NAME) $(INCLUDE)

$(NAME):	${OBJS}
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:
			${RM} ${NAME} $(OBJS)

re:		fclean all

.PHONY: clean fclean all re