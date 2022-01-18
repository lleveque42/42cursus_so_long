# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 16:38:44 by lleveque          #+#    #+#              #
#    Updated: 2022/01/18 12:20:35 by lleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix srcs/, so_long.c errors/map_errors.c parsing/parse_map.c \
			parsing/parse_map_utils.c game/moves.c)

SRCS_GNL	= $(addprefix gnl/, get_next_line_utils.c get_next_line.c)

OBJS	= ${SRCS:.c=.o}

OBJS_GNL = ${SRCS_GNL:.c=.o}

NAME = so_long

RM		= rm -f

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I/usr/include -Imlx -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${OBJS_GNL}
			${CC} ${CFLAGS} srcs/*.o srcs/*/*.o gnl/*.o -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

clean:
			${RM} ${OBJS} ${OBJS_GNL}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
