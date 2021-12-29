# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 16:52:46 by dmonteir          #+#    #+#              #
#    Updated: 2021/12/29 17:36:53 by dmonteir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./includes/pipex.h

FILES =			./sources/pipex.c \
				./sources/this_pipe.c \

FILES_UTILS =	./utils/ft_bzero.c \
				./utils/ft_strncmp.c \
				./utils/ft_strdup.c \
				./utils/ft_split.c \
				./utils/ft_strjoin.c \

FILES_BONUS =	./sources_bonus/pipex_bonus.c \
				./sources_bonus/this_pipe_bonus.c \


RM = rm -f
OBJS = $(FILES:.c=.o)
OBJS_UTILS = $(FILES_UTILS:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)

all:		$(NAME) $(INCLUDE)

$(NAME):	${OBJS} ${OBJS_UTILS}
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ${OBJS_UTILS}

bonus:		${OBJS_BONUS} ${OBJS_UTILS}
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) ${OBJS_UTILS}

clean:
			$(RM) $(OBJS)

fclean:
			${RM} ${NAME} $(OBJS)

re:			fclean all

