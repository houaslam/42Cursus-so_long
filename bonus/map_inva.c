/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inva.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:25:00 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/23 07:34:16 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h" 

void	flood_fill(int y, int x, t_mlx mlx, t_data *data)
{
	if (mlx.res[y][x] == '1' || mlx.res[y][x] == '*' || mlx.res[y][x] == 'N')
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

void	check_int(t_mlx mlx)
{
	t_data	data;

	data.collect_n = 0;
	data.exit_n = 0;
	data.i = 0;
	data.j = 0;
	flood_fill(mlx.p_y, mlx.p_x, mlx, &data);
	if (data.collect_n != mlx.collect_num || data.exit_n != 1)
		ft_putstr_fd("invalid path");
	ft_free(&mlx);
}

void	map_dup(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (mlx->ptr[i])
		i++;
	mlx->res = malloc(sizeof(char *) * i);
	i = 0;
	while (mlx->ptr[i])
	{
		mlx->res[i] = ft_strdup(mlx->ptr[i]);
		i++;
	}
	mlx->res[i] = NULL;
}

void	ft_free(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->win_y)
	{
		free(mlx->res[i]);
		i++;
	}
	free(mlx->res);
}
