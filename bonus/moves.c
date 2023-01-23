/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 05:00:53 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/23 08:21:52 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h" 

void	left_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'C')
	{
		mlx->ptr[mlx->p_y][mlx->p_x - 1] = '0';
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_x--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		put1_image(mlx, mlx->ghost_l, mlx->p_x, mlx->p_y);
		mlx->collect_num--;
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == '0' \
	|| mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'P')
	{
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_x--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->ghost_l, mlx->p_x, mlx->p_y);
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'E' && mlx->collect_num == 0)
	{
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_x--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->ghost_l, mlx->p_x, mlx->p_y);
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
		ft_printf("GAME OVER!!");
		ft_exit(mlx);
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x - 1] == 'N')
	{
		ft_printf("U LOST!!");
		ft_exit(mlx);
	}
}

void	down_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'C')
	{
		mlx->ptr[mlx->p_y + 1][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_y++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		put1_image(mlx, mlx->ghost_f, mlx->p_x, mlx->p_y);
		mlx->collect_num--;
			mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
	}
	else if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == '0'\
	|| mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'P')
	{
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_y++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->ghost_f, mlx->p_x, mlx->p_y);
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
	}
	else if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'E' && mlx->collect_num == 0)
	{
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_y++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->ghost_f, mlx->p_x, mlx->p_y);
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
		ft_printf("GAME OVER!!");
		ft_exit(mlx);
	}
		else if (mlx->ptr[mlx->p_y + 1][mlx->p_x] == 'N')
	{
		ft_printf("U LOST!!");
		ft_exit(mlx);
	}
}

void	right_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'C')
	{
		mlx->ptr[mlx->p_y][mlx->p_x + 1] = '0';
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_x++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		put1_image(mlx, mlx->ghost_r, mlx->p_x, mlx->p_y);
		mlx->collect_num--;
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == '0'\
	|| mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'P')
	{
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_x++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->ghost_r, mlx->p_x, mlx->p_y);
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'E' && mlx->collect_num == 0)
	{
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_x++;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->ghost_r, mlx->p_x, mlx->p_y);
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
		ft_printf("GAME OVER!!");
		ft_exit(mlx);
	}
	else if (mlx->ptr[mlx->p_y][mlx->p_x + 1] == 'N')
	{
		printf("U LOST!!");
		ft_exit(mlx);
	}
}

void	up_move(t_mlx *mlx)
{
	if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'C')
	{
		mlx->ptr[mlx->p_y - 1][mlx->p_x] = '0';
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_y--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		put1_image(mlx, mlx->ghost_b, mlx->p_x, mlx->p_y);
		mlx->collect_num--;
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
	}
	else if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == '0'\
	|| mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'P')
	{
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_y--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->ghost_b, mlx->p_x, mlx->p_y);
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
	}
	else if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'E' && mlx->collect_num == 0)
	{
		put1_image(mlx, mlx->floor, mlx->p_x, mlx->p_y);
		mlx->p_y--;
		mlx->ptr[mlx->p_y][mlx->p_x] = 'P';
		put1_image(mlx, mlx->ghost_b, mlx->p_x, mlx->p_y);
		mlx->steps++;
		put1_image(mlx, mlx->wall, 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 0, 0, 0, ft_itoa(mlx->steps));
		ft_printf("GAME OVER!!");
		ft_exit(mlx);
	}
	else if (mlx->ptr[mlx->p_y - 1][mlx->p_x] == 'N')
	{
		ft_printf("U LOST!!");
		ft_exit(mlx);
	}
}

void	put1_image(t_mlx *mlx, void *texture, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
	texture, (mlx->img_x) * x, mlx->img_y * y);
}
