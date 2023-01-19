/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:07:21 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/19 14:37:00 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

#define up 13
#define arrow_up 126
#define down 1
#define arrow_down 125
#define left 0
#define arrow_left 123
#define right 2
#define arrow_right 124

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		x;
	int		y;
    char    *path;
}				t_data;

typedef struct	mlx {
	void *mlx;
	void *mlx_win;
	int fd;
	int size_x;
	int size_y;
}			mlx_data;


typedef struct	player {
	int x;
	int y;
}			player_data;

typedef struct data{
	int b;
	int i;
	int j;
	int k;
	int size_x;
	int size_y;
}		int_data;

#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>


void images(char **av);
char *image_init(char ptr, char *path);
void make_path(mlx_data mlx, t_data img, char **ptr);
char *path_find(char av, t_data img, int *i);
void path_prot(char **av);
void    put_image(mlx_data mlx, t_data img, int_data data);
char **read_data(mlx_data *mlx, char **av);
int	ft_exit(mlx_data *mlx);


// get_next_line
char	*ft_handle(char *buf);
char	*after(char *buf);
char	*ft_check(char *buf, int fd);
char	*get_next_line(int fd);

//libft

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
void	ft_putstr_fd(char *s);

#endif