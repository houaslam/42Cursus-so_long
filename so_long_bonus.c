/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:22:45 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/29 17:31:40 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h" 

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
		ft_exit(mlx);
	return (0);
}

void	make_path(t_mlx *mlx, char **ptr)
{
	mlx->x = 0;
	while (ptr[mlx->x])
	{
		mlx->y = 0;
		while (ptr[mlx->x][mlx->y])
		{
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			mlx->floor, (mlx->img_x) * mlx->y, mlx->img_y * mlx->x);
			put_element(ptr[mlx->x][mlx->y], mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	element_prot(ptr, mlx);
	check(*mlx);
}

void	read_data(t_mlx *mlx)
{
	int	j;

	j = 0;
	mlx->win_x = 0;
	read_data1(mlx);
	while (mlx->ptr[j])
	{
		mlx->win_x = 0;
		while (mlx->ptr[j][mlx->win_x])
		{
			if (mlx->ptr[j][mlx->win_x] == 'P')
			{
				mlx->p_x = mlx->win_x;
				mlx->p_y = j;
			}
			mlx->win_x++;
		}
		j++;
	}
	mlx->ptr[j] = NULL;
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		ft_putstr_fd("INVALID ARGUMENTS !!");
	mlx.img_x = 0;
	mlx.steps = 0;
	mlx.img_y = 0;
	mlx.fram_n = 0;
	mlx.f = 1;
	mlx.mlx = mlx_init();
	arg_prot(&mlx, av);
	init(&mlx);
	read_data(&mlx);
	map_prot(mlx);
	mlx.mlx_win = mlx_new_window(mlx.mlx, \
	mlx.win_x * 40, mlx.win_y * 40, "so_long");
	if (mlx.mlx_win == NULL || mlx.mlx == NULL)
		exit(1);
	make_path(&mlx, mlx.ptr);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, \
	mlx.wall, 0, 0);
	mlx_hook(mlx.mlx_win, 17, 0, ft_exit, &mlx);
	mlx_hook(mlx.mlx_win, 2, 0, ft_moves, &mlx);
	mlx_loop_hook(mlx.mlx, enemy_ani, &mlx);
	mlx_loop(mlx.mlx);
}
