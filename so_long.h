/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:07:21 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/20 01:21:47 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

#define up 13
#define arrow_up 126
#define down 1
#define arrow_down 125
#define left 0
#define arrow_left 123
#define right 2
#define arrow_right 124

typedef struct mlx {
	void	*mlx;
	void	*mlx_win;
	//
	int		win_x;
	int		win_y;
	//
	char	*path;
	void	*img;
	int		img_x;
	int		img_y;
	// 
	int		i;
	int		j;
	//
	int		p_x;
	int		p_y;
	//
	void	*ghost_f;
	void	*exit;
	void	*wall;
	void	*floor;
	void	*collect_f;
	// void	*ghost_l;
	// void	*ghost_b;
	// void	*ghost_r;
}			t_mlx;

typedef struct data{
	int	b;
	int	i;
	int	j;
	int	k;
	int	size_x;
	int	size_y;
}	t_data;

void	images(char **av);
char	*image_init(char ptr, char *path);
void	make_path(t_mlx *mlx, char **ptr);
void	path_find(char av, t_mlx mlx);
void	path_prot(char **av);
void	put_image(t_mlx mlx);
char	**read_data(t_mlx *mlx, char **av);
int		ft_exit(t_mlx *mlx);
void	init(t_mlx *mlx);

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
void	ft_freestr(char **arr, int p);

#endif