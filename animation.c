/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:43:29 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/23 03:22:03 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void    enemy(t_mlx *mlx)
{
    mlx->i = 0;
	while (mlx->ptr[mlx->i])
	{
		mlx->j = 0;
		while (mlx->ptr[mlx->i][mlx->j])
		{
			if (mlx->ptr[mlx->i][mlx->j] == 'N')
			{
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