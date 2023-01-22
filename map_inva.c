/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inva.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:25:00 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/22 23:44:46 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	flood_fill(int y, int x, t_mlx mlx, t_data *data)
{
	if (mlx.ptr[y][x] == '1' || mlx.ptr[y][x] \
	== '*' || mlx.ptr[y][x] == '+' || (mlx.ptr[y][x] == '-'))
		return ;
	else if (mlx.ptr[y][x] == 'E')
	{
		mlx.ptr[y][x] = '-';
		data->exit_n++;
		return ;
	}
	else if (mlx.ptr[y][x] == 'C')
	{
		mlx.ptr[y][x] = '*';
		data->collect_n++;
	}
	else if (mlx.ptr[y][x] == '0')
		mlx.ptr[y][x] = '+';
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
	while (mlx.ptr[data.i])
	{
		data.j = 0;
		while (mlx.ptr[data.i][data.j])
		{
			if (mlx.ptr[data.i][data.j] == '+')
				mlx.ptr[data.i][data.j] = '0';
			else if (mlx.ptr[data.i][data.j] == '*')
				mlx.ptr[data.i][data.j] = 'C';
			else if (mlx.ptr[data.i][data.j] == '-')
				mlx.ptr[data.i][data.j] = 'E';
			data.j++;
		}
		data.i++;
	}
}
