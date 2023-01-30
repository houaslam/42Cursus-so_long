/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:43:29 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/30 18:39:29 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h" 

int	enemy(t_mlx *mlx)
{
	while (mlx->ptr[mlx->x])
	{
		mlx->y = 0;
		while (mlx->ptr[mlx->x][mlx->y])
		{
			if (mlx->ptr[mlx->x][mlx->y] == 'N')
			{
				mlx->n_x = mlx->y;
				mlx->n_y = mlx->x;
				directions(mlx);
			}
			mlx->y++;
		}
		mlx->x++;
	}
	return (0);
}

int	enemy_ani(t_mlx *mlx)
{
	frame(mlx);
	if (mlx->fram_n == 5000)
	{
		mlx->x = 0;
		mlx->y = 0;
		enemy(mlx);
		mlx->fram_n = 0;
	}
	mlx->fram_n++;
	return (0);
}

void	directions(t_mlx *mlx)
{
	one_direction(mlx);
	if (mlx->f == 1 && mlx->ptr[mlx->n_y][mlx->n_x + 1] != '1' \
	&& mlx->ptr[mlx->n_y][mlx->n_x + 1] != 'C' \
	&& mlx->ptr[mlx->n_y][mlx->n_x + 1] != 'E')
	{
		if (mlx->ptr[mlx->n_y][mlx->n_x + 1] == 'P')
			ft_exit(mlx);
		mlx->ptr[mlx->n_y][mlx->n_x] = '0';
		put1_image(mlx, mlx->floor, mlx->n_y, mlx->n_x);
		mlx->n_x++;
		mlx->y++;
		mlx->ptr[mlx->n_y][mlx->n_x] = 'N';
		put1_image(mlx, mlx->enemy_od, mlx->n_y, mlx->n_x);
	}
	else if (mlx->f == 1)
		mlx->f = -1;
}

void	one_direction(t_mlx *mlx)
{
	if (mlx->f == -1 && mlx->ptr[mlx->n_y][mlx->n_x - 1] != '1' \
	&& mlx->ptr[mlx->n_y][mlx->n_x - 1] != 'C' \
	&& mlx->ptr[mlx->n_y][mlx->n_x - 1] != 'E')
	{
		if (mlx->ptr[mlx->n_y][mlx->n_x - 1] == 'P')
			ft_exit(mlx);
		mlx->ptr[mlx->n_y][mlx->n_x] = '0';
		put1_image(mlx, mlx->floor, mlx->n_y, mlx->n_x);
		mlx->n_x--;
		mlx->ptr[mlx->n_y][mlx->n_x] = 'N';
		put1_image(mlx, mlx->enemy, mlx->n_y, mlx->n_x);
	}
	else if (mlx->f == -1)
		mlx->f = 1;
}
