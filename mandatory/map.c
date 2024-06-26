/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:25:00 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/31 19:51:01 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h" 

void	map_dup(t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx->res = malloc(sizeof(char *) * mlx->win_y);
	if (!mlx->res)
		ft_putstr_fd("ALLOCATION FAILED !!");
	while (mlx->ptr[i])
	{
		mlx->res[i] = ft_strdup(mlx->ptr[i]);
		i++;
	}
}

void	check(t_mlx mlx)
{
	t_data	data;

	data.collect_n = 0;
	data.exit_n = 0;
	data.i = 0;
	data.j = 0;
	map_dup(&mlx);
	flood_fill(mlx.p_y, mlx.p_x, mlx, &data);
	if (data.collect_n != mlx.collect_num || data.exit_n != 1)
		ft_putstr_fd("INVALID PATH");
	ft_free(mlx.res, mlx.win_y - 1);
}

void	flood_fill(int y, int x, t_mlx mlx, t_data *data)
{
	if (mlx.res[y][x] == '1' || mlx.res[y][x] == '*')
		return ;
	else if (mlx.res[y][x] == 'E')
	{
		mlx.res[y][x] = '*';
		data->exit_n++;
		return ;
	}
	else if (mlx.res[y][x] == 'C')
	{
		mlx.res[y][x] = '*';
		data->collect_n++;
	}
	else if (mlx.res[y][x] == '0')
		mlx.res[y][x] = '*';
	flood_fill(y - 1, x, mlx, data);
	flood_fill(y, x - 1, mlx, data);
	flood_fill(y + 1, x, mlx, data);
	flood_fill(y, x + 1, mlx, data);
}
