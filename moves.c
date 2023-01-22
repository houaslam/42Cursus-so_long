/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 05:00:53 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/22 18:12:37 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'C')
	{
		mlx->ptr[mlx->p_y][mlx->p_x - 1] = '0';
		put1_image(mlx, mlx->floor);
		mlx->p_x--;
		put1_image(mlx, mlx->floor);
		put1_image(mlx, mlx->ghost_l);
		mlx->collect_num--;
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == '0' \
	|| mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'P')
	{
		put1_image(mlx, mlx->floor);
		mlx->p_x--;
		put1_image(mlx, mlx->ghost_l);
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'E' && mlx->collect_num == 0)
	{
		put1_image(mlx, mlx->floor);
		mlx->p_x--;
		put1_image(mlx, mlx->ghost_l);
		ft_printf("GAME OVER!!");
		exit(0);
	}
}

void	down_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'C')
	{
		mlx->ptr[mlx->p_y + 1][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor);
		mlx->p_y++;
		put1_image(mlx, mlx->floor);
		put1_image(mlx, mlx->ghost_f);
		mlx->collect_num--;
	}
	else if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == '0'\
	|| mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'P')
	{
		put1_image(mlx, mlx->floor);
		mlx->p_y++;
		put1_image(mlx, mlx->ghost_f);
	}
	else if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'E' && mlx->collect_num == 0)
	{
		put1_image(mlx, mlx->floor);
		mlx->p_y++;
		put1_image(mlx, mlx->ghost_f);
		ft_printf("GAME OVER!!");
		exit(0);
	}
}

void	right_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'C')
	{
		mlx->ptr[mlx->p_y][mlx->p_x + 1] = '0';
		put1_image(mlx, mlx->floor);
		mlx->p_x++;
		put1_image(mlx, mlx->floor);
		put1_image(mlx, mlx->ghost_r);
		mlx->collect_num--;
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == '0'\
	|| mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'P')
	{
		put1_image(mlx, mlx->floor);
		mlx->p_x++;
		put1_image(mlx, mlx->ghost_r);
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'E' && mlx->collect_num == 0)
	{
		put1_image(mlx, mlx->floor);
		mlx->p_x++;
		put1_image(mlx, mlx->ghost_r);
		ft_printf("GAME OVER!!");
		exit(0);
	}
}

void	up_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'C')
	{
		mlx->ptr[mlx->p_y - 1][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor);
		mlx->p_y--;
		put1_image(mlx, mlx->floor);
		put1_image(mlx, mlx->ghost_b);
		mlx->collect_num--;
	}
	else if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == '0'\
	|| mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'P')
	{
		put1_image(mlx, mlx->floor);
		mlx->p_y--;
		put1_image(mlx, mlx->ghost_b);
	}
	else if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'E' && mlx->collect_num == 0)
	{
		put1_image(mlx, mlx->floor);
		mlx->p_y--;
		put1_image(mlx, mlx->ghost_b);
		ft_printf("GAME OVER!!");
		exit(0);
	}
}

void	put1_image(t_mlx *mlx, void *texture)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
	texture, (mlx->img_x) * mlx->p_x, mlx->img_y * mlx->p_y);
}
