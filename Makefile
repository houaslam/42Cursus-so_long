# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:10:20 by houaslam          #+#    #+#              #
#    Updated: 2023/01/18 14:02:13 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Imlx

SRCS =  so_long.c \
		get_next_line.c \
		libft.c \
		outils.c

all : ${NAME}

OBJ = ${SRCS:.c=.o}

${NAME} : ${OBJ}
	cc  ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${OBJ} -o ${NAME}

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)

re: fclean all