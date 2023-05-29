# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 14:51:02 by pdelanno          #+#    #+#              #
#    Updated: 2023/05/18 10:28:47 by pdelanno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MINILIBX_FLAGS = -Lmlx_linux -lmlx_linux -L/user/lib -Imlx_linux \
-lXext -lX11 -lm -lz

SRCS = so_long.c map.c init.c hook.c window.c check_map.c convert.c free.c \
move.c get_next_line/*.c printf/*.c utils/*.c

OBJS = $(patsubst %.c, %.o, $(wildcard $(SRCS)))

HEADERS = -I ./include -I $(LIBMLX)/mlx.h

LIBS = ./minilibx-linux/libmlx_Linux.a -Lmlx_Linux -lX11 -lXext -lm

CFLAGS = -g -Werror -Wall -Wextra

.c.o:
		@cc ${CFLAGS} -c $^ -o $@

$(NAME):	${OBJS}
			@cc $(SRCS) $(HEADERS) $(LIBS) $(CFLAGS) -o $(NAME)
			@echo "Compilation successful!"

all:		${NAME}

clean:
		@rm -f ${OBJS}

fclean:		clean
		@cd utils && rm -f ${NAME}
		@cd printf && rm -f ${NAME}
		@cd get_next_line && rm -f ${NAME}
		@rm -f ${NAME}
		@echo "All clean!"

re: fclean all

.PHONY: all clean fclean re
