/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:22:45 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/23 08:28:23 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h" 

int	ft_moves(int keycode, t_mlx *mlx)
{
	if (keycode == LEFT || keycode == ARROW_LEFT)
		left_move(mlx);
	else if (keycode == UP || keycode == ARROW_UP)
		up_move(mlx);
	else if (keycode == DOWN || keycode == ARROW_DOWN)
		down_move(mlx);
	else if (keycode == RIGHT || keycode == ARROW_RIGHT)
		right_move(mlx);
	else if (keycode == 53)
	{
		ft_printf("GAME OVER !!");
		ft_exit(mlx);
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
	mlx->win_x = 0;
	mlx->ptr = malloc(sizeof(char **));
	mlx->ptr[mlx->win_y] = get_next_line(mlx->fd);
	if (!mlx->ptr[mlx->win_y])
		ft_putstr_fd("invalid map");
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

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.f = 0;
	(void)ac;
	mlx.img_x = 0;
	mlx.img_y = 0;
	mlx.mlx = mlx_init();
	arg_prot(&mlx, av);
	init(&mlx);
	read_data(&mlx);
	map_dup(&mlx);
	map_prot(mlx);
	mlx.mlx_win = mlx_new_window(mlx.mlx, \
	mlx.win_x * 40, mlx.win_y * 40, "so_long");
	if (mlx.mlx_win == NULL || mlx.mlx == NULL)
		exit(1);
	make_path(&mlx, mlx.ptr);
	enemy(&mlx);
	check_int(mlx);
	mlx_hook(mlx.mlx_win, 17, 0, ft_exit, &mlx);
	mlx.steps = 0;
	mlx_loop_hook(mlx.mlx, anime, &mlx);
	mlx_key_hook(mlx.mlx_win, ft_moves, &mlx);
	mlx_loop(mlx.mlx);
}

int	anime(t_mlx *mlx)
{
	frame(mlx);
	enemy_ani(mlx);
	return (1);
}