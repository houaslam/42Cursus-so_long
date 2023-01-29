/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:28:29 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/29 17:10:37 by houaslam         ###   ########.fr       */
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
	else
	{
		frame_2(mlx);
		frame_3(mlx);
		mlx->fram++;
	}
	return (0);
}

void	frame_2(t_mlx *mlx)
{
	if (mlx->fram == 30000)
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
}

void	frame_3(t_mlx *mlx)
{
	if (mlx->fram == 15000)
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
}

void	make_coins(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->ptr[mlx->x])
	{
		mlx->y = 0;
		while (mlx->ptr[mlx->x][mlx->y])
		{
			if (mlx->ptr[mlx->x][mlx->y] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx, \
				mlx->mlx_win, mlx->floor, \
				(mlx->img_x) * mlx->y, mlx->img_y * mlx->x);
				mlx_put_image_to_window(mlx->mlx, \
				mlx->mlx_win, mlx->collect_f, \
				(mlx->img_x) * mlx->y, mlx->img_y * mlx->x);
			}
			mlx->y++;
		}
		mlx->x++;
	}
}
