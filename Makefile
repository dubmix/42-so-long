# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelanno <pdelanno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 14:51:02 by pdelanno          #+#    #+#              #
#    Updated: 2023/10/13 15:24:45 by pdelanno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = src/so_long.c \
			src/map.c \
			src/init.c \
			src/window.c \
			src/hook.c \
			src/check_map.c \
			src/convert.c \
			src/free.c \
			src/move.c \
			src/utils/*.c \
			src/utils/ft_printf/*.c \
			src/utils/get_next_line/*.c

OBJS = $(patsubst %.c, %.o, $(wildcard $(SRCS)))

HEADERS = -I ./include -I $(LIBMLX)/mlx.h

LIBS = ./minilibx/libmlx_Linux.a -Lmlx_Linux -lX11 -lXext -lm

CFLAGS = -Werror -Wall -Wextra -g

.c.o:
			@cc ${CFLAGS} -c $^ -o $@

$(NAME):	minilibx ${OBJS}
			@cc $(SRCS) $(HEADERS) $(LIBS) $(CFLAGS) -o $(NAME)
			@echo "\033[1;5mProgram is ready!\033[0m"

minilibx:
			@if ! [ -d "/minilibx" ]; then \
				git clone https://github.com/42Paris/minilibx-linux.git minilibx; \
				cd ./minilibx; ./config; \
			fi

all:		${NAME}

clean:
			@rm -f ${OBJS}

fclean:		clean
			@cd src/utils && rm -f ${NAME}
			@cd src/utils/ft_printf && rm -f ${NAME}
			@cd src/utils/get_next_line && rm -f ${NAME}
			@rm -f ${NAME}
			@echo "\033[1mAll clean!\033[0m"

re: fclean all

.PHONY: all clean fclean re
