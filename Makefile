# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 16:47:09 by lcamilo-          #+#    #+#              #
#    Updated: 2022/10/19 20:35:17 by lcamilo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
LIBFT		= libft
MINILIB		= mlx
PRINTF		= printf
CFLAGS 		= -Wall -Wextra -Werror -Imlx -I.
CC			= cc
SRC_PATH	= ./
OPTIONS		= -Ilibft -Lmlx -g3 -fsanitize=address
SRC 		= 	main.c						\
				player.c					\
				movement.c					\
				window.c					\
				path_finding.c				\
				map.c						\
				checking.c					\
				gnl/get_next_line.c			\
				gnl/get_next_line_utils.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJS		= ${SRCS:.c=.o}

all: printf ${NAME}

$(LIBFT):
			make -C $(LIBFT)
			cp ./libft/libft.a libft.a

$(MINILIB):
			make -C $(MINILIB)
			cp ./mlx/libmlx.dylib libmlx.dylib

printf:
			make -C $(PRINTF)
			cp ./printf/libftprintf.a libftprintf.a

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} $(LIBFT) $(MINILIB) $(PRINTF)
		$(CC)  ${OPTIONS} -lmlx -lftprintf -L. -Llibft -I. -lft -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

clean:
			${RM} ${OBJS}
			make fclean -C $(LIBFT)
			make clean -C $(MINILIB)
			make fclean -C $(PRINTF)

fclean:		clean
			${RM} ${NAME} libmlx.dylib *.a

re:			fclean all

.PHONY: re ignore fclean clean all $(LIBFT) $(NAME) $(MINILIB) $(PRINTF)