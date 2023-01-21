/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:51:43 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/21 14:26:59 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_find(char av, t_mlx mlx)
{
	if (av == 'P')
		mlx_put_image_to_window(mlx.mlx, \
		mlx.mlx_win, mlx.ghost_f, (mlx.img_x) * mlx.p_x, mlx.img_y * mlx.p_y);
	else if (av == '0')
		mlx_put_image_to_window(mlx.mlx, \
		mlx.mlx_win, mlx.floor, (mlx.img_x) * mlx.j, mlx.img_y * mlx.i);
	else if (av == 'E')
		mlx_put_image_to_window(mlx.mlx, \
		mlx.mlx_win, mlx.exit, (mlx.img_x) * mlx.j, mlx.img_y * mlx.i);
	else if (av == '1')
		mlx_put_image_to_window(mlx.mlx, \
		mlx.mlx_win, mlx.wall, (mlx.img_x) * mlx.j, mlx.img_y * mlx.i);
	else if (av == 'C')
		mlx_put_image_to_window(mlx.mlx, \
		mlx.mlx_win, mlx.collect_f, (mlx.img_x) * mlx.j, mlx.img_y * mlx.i);
	else
		ft_putstr_fd("Error");
}

void	init(t_mlx *mlx)
{
	mlx->ghost_f = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/ghost_f.xpm", &mlx->p_x, &mlx->p_y);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/exit.xpm", &mlx->img_x, &mlx->img_y);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/wall.xpm", &mlx->img_x, &mlx->img_y);
	mlx->floor = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/floor.xpm", &mlx->img_x, &mlx->img_y);
	mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/collect_f.xpm", &mlx->img_x, &mlx->img_y);
	mlx->ghost_l = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/ghost_l.xpm", &mlx->img_x, &mlx->img_y);
	mlx->ghost_b = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/ghost_b.xpm", &mlx->img_x, &mlx->img_y);
	mlx->ghost_r = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/ghost_r.xpm", &mlx->img_x, &mlx->img_y);
}

void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(1);
}

int	ft_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

void	make_coins(t_mlx *mlx)
{
	mlx->i = 0;
	while (mlx->ptr[mlx->i])
	{
		mlx->j = 0;
		while (mlx->ptr[mlx->i][mlx->j])
		{
			if (mlx->ptr[mlx->i][mlx->j] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx, \
				mlx->mlx_win, mlx->floor, \
				(mlx->img_x) * mlx->j, mlx->img_y * mlx->i);
				mlx_put_image_to_window(mlx->mlx, \
				mlx->mlx_win, mlx->collect_f, \
				(mlx->img_x) * mlx->j, mlx->img_y * mlx->i);
			}
			mlx->j++;
		}
		mlx->i++;
	}
}
