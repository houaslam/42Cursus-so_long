/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:43:29 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/23 08:28:21 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h" 

int	frame(t_mlx *mlx)
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

void	enemy(t_mlx *mlx)
{
	mlx->i = 0;
	while (mlx->ptr[mlx->i])
	{
		mlx->j = 0;
		while (mlx->ptr[mlx->i][mlx->j])
		{
			if (mlx->ptr[mlx->i][mlx->j] == 'N')
			{
				mlx->n_x = mlx->j;
				mlx->n_y = mlx->i;
				mlx_put_image_to_window(mlx->mlx, \
				mlx->mlx_win, mlx->floor, \
				(mlx->img_x) * mlx->j, mlx->img_y * mlx->i);
				mlx_put_image_to_window(mlx->mlx, \
				mlx->mlx_win, mlx->enemy, \
				(mlx->img_x) * mlx->j, mlx->img_y * mlx->i);
			}
			mlx->j++;
		}
		mlx->i++;
	}
}

int	enemy_ani(t_mlx *mlx)
{
	if (mlx->fram_n == 5000)
	{
		directions(mlx);
		mlx->fram_n = 0;
	}
	mlx->fram_n++;
	return (1);
}

void	directions(t_mlx *mlx)
{	
	if (mlx->ptr[mlx->n_y][mlx->n_x + 1] == '1')
		mlx->f = 0;
	if (mlx->ptr[mlx->n_y][mlx->n_x - 1] == '1')
		mlx->f = 1;
	if (mlx->f == 0 && mlx->ptr[mlx->n_y][mlx->n_x - 1] != '1')
	{
		if (mlx->ptr[mlx->n_y][mlx->n_x - 1] == 'P')
			ft_putstr_fd("you lost");
		mlx->ptr[mlx->n_y][mlx->n_x] = '0';
		put1_image(mlx, mlx->floor, mlx->n_x, mlx->n_y);
		(mlx->n_x)--;
		mlx->ptr[mlx->n_y][mlx->n_x] = 'N';
		put1_image(mlx, mlx->enemy, mlx->n_x, mlx->n_y);
	}
	if (mlx->f == 1 && mlx->ptr[mlx->n_y][mlx->n_x + 1] != '1' )
	{
		if (mlx->ptr[mlx->n_y][mlx->n_x + 1] == 'P')
			ft_putstr_fd("you lost");
		mlx->ptr[mlx->n_y][mlx->n_x] = '0';
		put1_image(mlx, mlx->floor, mlx->n_x, mlx->n_y);
		(mlx->n_x)++;
		mlx->ptr[mlx->n_y][mlx->n_x] = 'N';
		put1_image(mlx, mlx->enemy, mlx->n_x, mlx->n_y);
	}
}
