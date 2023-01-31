# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:10:20 by houaslam          #+#    #+#              #
#    Updated: 2023/01/31 20:09:50 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus
CFLAGS = -Wall -Wextra -Werror -Imlx

SRCS =  mandatory/get_next_line.c \
		mandatory/libft.c \
		mandatory/libft_2.c \
		mandatory/map.c \
		mandatory/moves.c \
		mandatory/outils.c \
		mandatory/protection.c \
		mandatory/split.c \
		mandatory/so_long.c

B_SRCS  =  	bonus/get_next_line.c \
			bonus/ft_itoa.c \
			bonus/enemy.c \
			bonus/coins.c \
			bonus/libft.c \
			bonus/libft_2.c \
			bonus/map.c \
			bonus/moves.c \
			bonus/outils.c \
			bonus/protection.c \
			bonus/so_long_bonus.c \
			bonus/split.c
all : ${NAME}

OBJ = ${SRCS:.c=.o}
B_OBJ = ${B_SRCS:.c=.o}

${NAME} : ${OBJ}
	cc  ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${OBJ} printf/libftprintf.a -o ${NAME}

bonus : ${B_OBJ}
	cc  ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${B_OBJ} printf/libftprintf.a -o ${BONUS}
clean :
	rm -f ${OBJ}
	rm -f $(B_OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all
