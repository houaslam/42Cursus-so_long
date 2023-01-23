# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:10:20 by houaslam          #+#    #+#              #
#    Updated: 2023/01/23 08:14:08 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus
CFLAGS = -Wall -Wextra -Werror -Imlx 

SRCS =  so_long_bonus.c \
		get_next_line.c \
		libft.c \
		outils.c \
		moves.c \
		protection.c \
		map_inva.c \
		animation.c \
		ft_itoa.c

all : ${NAME}

OBJ = ${SRCS:.c=.o}
B_OBJ = ${B_SRCS:.c=.o}

${NAME} : ${OBJ}
	cc  ${CFLAGS} -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g ${OBJ} printf/libftprintf.a -o ${NAME}

bonus : ${B_OBJ}
	cc  ${CFLAGS} -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g ${B_OBJ} printf/libftprintf.a -o ${BONUS}
clean :
	rm -f ${OBJ}
	rm -f $(B_OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

mine: all clean
yous: bonus clean