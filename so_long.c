/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:22:45 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/21 18:55:35 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moves(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		printf("GAME OVER !!");
		ft_exit(mlx);
	}
	else if (keycode == LEFT || keycode == ARROW_LEFT)
	{
		left_move(mlx);
		mlx->steps++;
		printf("NUM = %d\n", mlx->steps);
	}
	else if (keycode == UP || keycode == ARROW_UP)
	{
		up_move(mlx);
		mlx->steps++;
		printf("NUM = %d\n", mlx->steps);
	}
	else if (keycode == DOWN || keycode == ARROW_DOWN)
	{
		down_move(mlx);
		mlx->steps++;
		printf("NUM = %d\n", mlx->steps);
	}
	else if (keycode == RIGHT || keycode == ARROW_RIGHT)
	{
		right_move(mlx);
		mlx->steps++;
		printf("NUM = %d\n", mlx->steps);
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
	path_prot(ptr, mlx);
}

void	read_data(t_mlx *mlx)
{
	mlx->win_y = 0;
	mlx->ptr = malloc(sizeof(char **));
	mlx->ptr[mlx->win_y] = get_next_line(mlx->fd);
	if (!mlx->ptr[mlx->win_y])
	{
		free(mlx->ptr[mlx->win_y]);
		ft_putstr_fd("invalid map");
	}
	while (mlx->ptr[mlx->win_y])
	{
		mlx->win_x = 0;
		while (mlx->ptr[mlx->win_y][mlx->win_x])
		{
			if (mlx->ptr[mlx->win_y][mlx->win_x] == 'P')
			{
				mlx->p_x = mlx->win_x;
				mlx->p_y = mlx->win_y;
			}
			mlx->win_x++;
		}
		mlx->win_y++;
		mlx->ptr[mlx->win_y] = get_next_line(mlx->fd);
	}
}
int frame(t_mlx *mlx)
{
	if (mlx->fram == 5000)
	{
		mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
			, "textures/collect_f.xpm", &mlx->img_x, &mlx->img_y);
		make_coins(mlx);
		mlx->fram++;
	}
	else if (mlx->fram == 10000)
	{
		mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
			, "textures/collect_f2.xpm", &mlx->img_x, &mlx->img_y);
		make_coins(mlx);
		mlx->fram++;
	}
	else if (mlx->fram == 15000)
	{
		mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
			, "textures/collect_f3.xpm", &mlx->img_x, &mlx->img_y);
		make_coins(mlx);
		mlx->fram++;
	}
	else if (mlx->fram == 20000)
	{
		mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
			, "textures/collect_f4.xpm", &mlx->img_x, &mlx->img_y);
		make_coins(mlx);
		mlx->fram++;
	}
	else if (mlx->fram == 25000)
	{
		mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
			, "textures/collect_f5.xpm", &mlx->img_x, &mlx->img_y);
		make_coins(mlx);
		mlx->fram++;
	}
	else if (mlx->fram == 30000)
	{
		mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
			, "textures/collect_f6.xpm", &mlx->img_x, &mlx->img_y);
		make_coins(mlx);
		mlx->fram++;
	}
	else if (mlx->fram == 35000)
	{
		mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
			, "textures/collect_f7.xpm", &mlx->img_x, &mlx->img_y);
		make_coins(mlx);
		mlx->fram++;
	}
	else if (mlx->fram == 40000)
	{
		mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
			, "textures/collect_f8.xpm", &mlx->img_x, &mlx->img_y);
		make_coins(mlx);
		mlx->fram = 0;
	}
	else
		mlx->fram++;
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	(void)ac;
	mlx.img_x = 0;
	mlx.img_y = 0;
	mlx.fram = 0;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		exit(1);
	init(&mlx);
	arg_prot(&mlx, av);
	read_data(&mlx);
	map_prot(mlx);
	mlx.mlx_win = mlx_new_window(mlx.mlx, \
	mlx.win_x * 40, mlx.win_y * 40, "so_long");
	if (mlx.mlx_win == NULL)
		exit(1);
	make_path(&mlx, mlx.ptr);
	mlx_hook(mlx.mlx_win, 17, 0, ft_exit, &mlx);
	mlx.steps = 0;
	mlx_key_hook(mlx.mlx_win, ft_moves, &mlx);
	mlx_loop_hook(mlx.mlx, frame, &mlx);
	mlx_loop(mlx.mlx);
}
