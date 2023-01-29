/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 05:00:53 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/29 17:14:24 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h" 

void	left_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'C')
	{
		mlx->ptr[mlx->p_y][mlx->p_x - 1] = 'P';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_x--;
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		put1_image(mlx, mlx->ghost_l, mlx->p_y, mlx->p_x);
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
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		put1_image(mlx, mlx->ghost_l, mlx->p_y, mlx->p_x);
		put_steps(mlx);
	}
	else if ((mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'E' && mlx->collect_num == 0) \
	|| mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'N')
		ft_exit(mlx);
}

void	down_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'C')
	{
		mlx->ptr[mlx->p_y + 1][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_y++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		put1_image(mlx, mlx->ghost_f, mlx->p_y, mlx->p_x);
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
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		put1_image(mlx, mlx->ghost_f, mlx->p_y, mlx->p_x);
		put_steps(mlx);
	}
	else if ((mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'E' && mlx->collect_num == 0) \
	|| mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'N')
		ft_exit(mlx);
}

void	right_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'C')
	{
		mlx->ptr[mlx->p_y][mlx->p_x + 1] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_x++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		put1_image(mlx, mlx->ghost_r, mlx->p_y, mlx->p_x);
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
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		put1_image(mlx, mlx->ghost_r, mlx->p_y, mlx->p_x);
		put_steps(mlx);
	}
	else if ((mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'E' && mlx->collect_num == 0) \
	|| mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'N')
		ft_exit(mlx);
}

void	up_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'C')
	{
		mlx->ptr[mlx->p_y - 1][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		mlx->p_y--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		put1_image(mlx, mlx->ghost_b, mlx->p_y, mlx->p_x);
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
		put1_image(mlx, mlx->floor, mlx->p_y, mlx->p_x);
		put1_image(mlx, mlx->ghost_b, mlx->p_y, mlx->p_x);
		put_steps(mlx);
	}
	else if ((mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'E' && mlx->collect_num == 0) \
	||mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'N')
		ft_exit(mlx);
}

void	put_steps(t_mlx *mlx)
{
	char	*moves;

	if (mlx->collect_num == 0)
		put1_image(mlx, mlx->exit2, mlx->e_x, mlx->e_y);
	mlx->steps++;
	moves = ft_itoa(mlx->steps);
	put1_image(mlx, mlx->wall, 0, 0);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 5, 0, 0, moves);
	free(moves);
}
