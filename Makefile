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
MINILIB		= minilib
CFLAGS 		= -Wall -Wextra -Werror -Imlx
CC			= cc
SRC_PATH	= ./
OPTIONS		= -Ilibft -Imlx -g3 -fsanitize=address
SRC = main.c gnl/get_next_line.c gnl/get_next_line_utils.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJS		= ${SRCS:.c=.o}

all: ${NAME}

$(LIBFT):
			make -C $(LIBFT)
			mv ./libft/libft.a libft.a
			ar rcs libft.a ${OBJS}

$(MLX):
			make -C $(MINILIB)
			mv ./mlx/mlx.a mlx.a
			ar rcs mlx.a ${OBJS}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} $(LIBFT) $(MLX)
		$(CC)  -Ilibft -Lmlx -lmlx -L. -Llibft -I. -lft -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: re fclean clean all $(LIBFT) $(NAME) $(MINILIB)