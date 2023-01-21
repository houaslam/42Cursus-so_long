# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:10:20 by houaslam          #+#    #+#              #
#    Updated: 2023/01/20 21:35:24 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Imlx

SRCS =  so_long.c \
		get_next_line.c \
		libft.c \
		outils.c \
		moves.c \
		protection.c

all : ${NAME}

OBJ = ${SRCS:.c=.o}

${NAME} : ${OBJ}
	cc  ${CFLAGS} -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g ${OBJ} -o ${NAME}

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)

re: fclean all

mine: all clean