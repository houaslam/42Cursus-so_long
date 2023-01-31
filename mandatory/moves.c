/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 05:00:53 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/31 20:29:19 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h" 

void	left_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'C')
	{
		mlx->ptr[mlx->p_y][mlx->p_x - 1] = 'P';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_x--;
		mlx->collect_num--;
		put_steps(mlx);
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == '0' \
	|| mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'P')
	{
		mlx->ptr[mlx->p_y][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_x--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put_steps(mlx);
	}
	else if ((mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'E' && mlx->collect_num == 0))
		ft_exit(mlx);
	put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
	put1_image(mlx, mlx->ghost_l, mlx->p_y, mlx->p_x);
}

void	down_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'C')
	{
		mlx->ptr[mlx->p_y + 1][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_y++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		mlx->collect_num--;
		put_steps(mlx);
	}
	else if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == '0'\
	|| mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'P')
	{
		mlx->ptr[mlx->p_y][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_y++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put_steps(mlx);
	}
	else if ((mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'E' && mlx->collect_num == 0))
		ft_exit(mlx);
	put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
	put1_image(mlx, mlx->ghost_f, mlx->p_y, mlx->p_x);
}

void	right_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'C')
	{
		mlx->ptr[mlx->p_y][mlx->p_x + 1] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_x++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		mlx->collect_num--;
		put_steps(mlx);
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == '0'\
	|| mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'P')
	{
		mlx->ptr[mlx->p_y][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_x++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put_steps(mlx);
	}
	else if ((mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'E' && mlx->collect_num == 0))
		ft_exit(mlx);
	put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
	put1_image(mlx, mlx->ghost_r, mlx->p_y, mlx->p_x);
}

void	up_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'C')
	{
		mlx->ptr[mlx->p_y - 1][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_y--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		mlx->collect_num--;
		put_steps(mlx);
	}
	else if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == '0'\
	|| mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'P')
	{
		mlx->ptr[mlx->p_y][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_y--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put_steps(mlx);
	}
	else if ((mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'E' && mlx->collect_num == 0))
		ft_exit(mlx);
	put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
	put1_image(mlx, mlx->ghost_b, mlx->p_y, mlx->p_x);
}

void	put_steps(t_mlx *mlx)
{
	if (mlx->collect_num == 0)
		put1_image(mlx, mlx->exit2, mlx->e_x, mlx->e_y);
	mlx->steps++;
	ft_printf("NUM OF STEPS = [%d]\n", mlx->steps);
}
