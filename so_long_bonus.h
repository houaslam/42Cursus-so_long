/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:44:16 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/23 03:21:53 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "printf/ft_printf.h"

# define UP 13
# define ARROW_UP 126
# define DOWN 1
# define ARROW_DOWN 125
# define LEFT 0
# define ARROW_LEFT 123
# define RIGHT 2
# define ARROW_RIGHT 124

typedef struct mlx {
	void	*mlx;
	void	*mlx_win;
	int		win_x;
	int		win_y;
	char	*path;
	void	*img;
	int		img_x;
	int		img_y;
	int		i;
	int		j;
	int		p_x;
	int		p_y;
	void	*ghost_f;
	void	*exit;
	void	*wall;
	void	*floor;
	void	*collect_f;
	void	*ghost_l;
	void	*ghost_b;
	void	*ghost_r;
	void	*exit2;
	char	**ptr;
	int		collect_num;
	int		fram;
	int		fd;
	int		steps;
	char	**res;
	void	*enemy;
}			t_mlx;

typedef struct data{
	int				b;
	int				i;
	int				j;
	int				k;
	unsigned int	len;
	int				exit_n;
	int				collect_n;
}	t_data;

//so_long 
void	make_path(t_mlx *mlx, char **ptr);
void	read_data(t_mlx *mlx);
int		ft_moves(int keycode, t_mlx *mlx);
int		frame(t_mlx *mlx);
void	map_prot(t_mlx mlx);
void	path_prot(char **av, t_mlx *mlx);
void	map_prot2(t_mlx mlx, t_data data);
void	path_find(char av, t_mlx mlx);
void	init(t_mlx *mlx);
int		ft_exit(t_mlx *mlx);
void	make_coins(t_mlx *mlx);
void	put1_image(t_mlx *mlx, void *texture);
void	arg_prot(t_mlx *mlx, char **av);
void	steps(t_mlx *mlx, int keycode);
void	flood_fill(int x, int y, t_mlx mlx, t_data *data);
void	check_int(t_mlx mlx);
void	map_dup(t_mlx *mlx);
void	ft_free(t_mlx *mlx);

//moves

void	left_move(t_mlx *mlx);
void	down_move(t_mlx *mlx);
void	right_move(t_mlx *mlx);
void	up_move(t_mlx *mlx);

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
void	ft_putstr_fd(char *s, t_mlx *mlx);
void	ft_freestr(char **arr, int p);
int		ft_strnstr(char *big, char *small);

#endif