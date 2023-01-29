/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:44:16 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/29 15:38:49 by houaslam         ###   ########.fr       */
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
# include "../printf/ft_printf.h"

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
	void	*img;
	void	*exit;
	void	*wall;
	void	*enemy;
	void	*floor;
	void	*mlx_win;
	void	*ghost_f;
	void	*ghost_l;
	void	*ghost_b;
	void	*ghost_r;
	void	*collect_f;
	void	*exit2;
	char	*fin;
	char	**res;
	char	**ptr;
	int		x;
	int		y;
	int		f;
	int		fd;
	int		p_x;
	int		n_x;
	int		p_y;
	int		n_y;
	int		e_x;
	int		e_y;
	int		fram;
	int		win_x;
	int		win_y;
	int		img_x;
	int		img_y;
	int		steps;
	int		fram_n;
	int		collect_num;
}			t_mlx;

typedef struct data{
	int				b;
	int				i;
	int				j;
	int				k;
	int				exit_n;
	int				collect_n;
	unsigned int	len;
}	t_data;

//so_long 
void	put_element(char av, t_mlx *mlx);
void	put_steps(t_mlx *mlx);
void	put1_image(t_mlx *mlx, void *texture, int x, int y);
void	make_path(t_mlx *mlx, char **ptr);
void	make_coins(t_mlx *mlx);
void	read_data(t_mlx *mlx);
void	read_data1(t_mlx *mlx);
void	map_prot(t_mlx mlx);
void	map_prot2(t_mlx mlx, t_data data);
void	map_dup(t_mlx *mlx);
void	ft_free(char **ptr, int i);
int		ft_moves(int keycode, t_mlx *mlx);
int		ft_exit(t_mlx *mlx);
int		frame(t_mlx *mlx);
void	frame_2(t_mlx *mlx);
void	frame_3(t_mlx *mlx);
int		enemy_ani(t_mlx *mlx);
int		enemy(t_mlx *mlx);
void	arg_prot(t_mlx *mlx, char **av);
void	init(t_mlx *mlx);
void	flood_fill(int x, int y, t_mlx mlx, t_data *data);
void	check(t_mlx mlx);
void	element_prot(char **av, t_mlx *mlx);
void	directions(t_mlx *mlx);
void	one_direction(t_mlx *mlx);

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
char	*ft_join(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_sign(long int nb, int j, char *str);
int		ft_count(long int nb);
char	*ft_itoa(int n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
void	ft_putstr_fd(char *s);
int		ft_strnstr(char *big, char *small);

// split 
int		ft_dim1(char *s, char c);
char	**ft_freestr(char **arr, int p);
char	**ft_split(char const *s, char c);
char	**ft_func(char **arr, char *s, char c);

#endif