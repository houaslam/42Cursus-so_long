/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:22:45 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/20 01:24:48 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moves(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		ft_exit(mlx);
	else if (keycode == left || keycode == arrow_left)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->floor, (mlx->img_x) * mlx->p_x, mlx->img_y * mlx->p_y);
		mlx->p_x--;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ghost_f, (mlx->img_x) * mlx->p_x, mlx->img_y * mlx->p_y);
	}
	else if (keycode == up || keycode == arrow_up)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->floor, (mlx->img_x) * mlx->p_x, mlx->img_y * mlx->p_y);
		mlx->p_y--;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ghost_f, (mlx->img_x) * mlx->p_x, mlx->img_y * mlx->p_y);
	}
	else if (keycode == down || keycode == arrow_down)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->floor, (mlx->img_x) * mlx->p_x, mlx->img_y * mlx->p_y);
		mlx->p_y++;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ghost_f, (mlx->img_x) * mlx->p_x, mlx->img_y * mlx->p_y);
	}
	else if (keycode == right || keycode == arrow_right)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->floor, (mlx->img_x) * mlx->p_x, mlx->img_y * mlx->p_y);
		mlx->p_x++;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ghost_f, (mlx->img_x) * mlx->p_x, mlx->img_y * mlx->p_y);
	}
	return (0);
}

void	make_path(t_mlx *mlx, char **ptr)
{
	mlx->i = 0;
	while (ptr[mlx->i])
	{
		mlx->j = 0;
		while (ptr[mlx->i][mlx->j])
		{
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->floor, (mlx->img_x) * mlx->j, mlx->img_y * mlx->i);
			path_find(ptr[mlx->i][mlx->j], *mlx);
			mlx->j++;
		}
		mlx->i++;
	}
	path_prot(ptr);
}

char	**read_data(t_mlx *mlx, char **av)
{
	char	**ptr;
	int		fd;

	ptr = malloc(sizeof(char **));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("map Error");
	ptr[mlx->win_y] = get_next_line(fd);
	while (ptr[mlx->win_y])
	{
		mlx->win_x = 0;
		while (ptr[mlx->win_y][mlx->win_x])
		{
			if (ptr[mlx->win_y][mlx->win_x] == 'P')
			{
				mlx->p_x = mlx->win_x;
				mlx->p_y = mlx->win_y;
			}
			mlx->win_x++;
		}
		mlx->win_y++;
		ptr[mlx->win_y] = get_next_line(fd);
	}
	return (ptr);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	char	**ptr;

	(void)ac;
	mlx.img_x = 0;
	mlx.img_y = 0;
	mlx.mlx = mlx_init();
	init(&mlx);
	ptr = read_data(&mlx, av);
	printf("%d\n", mlx.win_x);
	printf("%d\n", mlx.win_y);
	mlx.win_x--;
	if (mlx.win_x <= mlx.win_y)
		ft_putstr_fd("map should be rectangular");
	mlx.mlx_win = mlx_new_window(mlx.mlx, \
	mlx.win_x * 40, mlx.win_y * 40, "so_long");
	make_path(&mlx, ptr);
	mlx_hook(mlx.mlx_win, 17, 0, ft_exit, &mlx);
	mlx_key_hook(mlx.mlx_win, ft_moves, &mlx);
	mlx_loop(mlx.mlx);
}

void	init(t_mlx *mlx)
{
	mlx->ghost_f = mlx_xpm_file_to_image(mlx->mlx \
	, "img/ghost_f.xpm", &mlx->p_x, &mlx->p_y);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx \
	, "img/exit.xpm", &mlx->img_x, &mlx->img_y);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx \
	, "img/wall.xpm", &mlx->img_x, &mlx->img_y);
	mlx->floor = mlx_xpm_file_to_image(mlx->mlx \
	, "img/floor.xpm", &mlx->img_x, &mlx->img_y);
	mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
	, "img/collect_f.xpm", &mlx->img_x, &mlx->img_y);
}

