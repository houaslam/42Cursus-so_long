/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:51:43 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/20 00:04:47 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void path_find(char av, t_mlx mlx)
{
	if (av == 'P')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.ghost_f, (mlx.img_x) * mlx.p_x, mlx.img_y * mlx.p_y);
	else if (av == '0')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.floor, (mlx.img_x) * mlx.j, mlx.img_y * mlx.i);
	else if (av == 'C')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.collect_f, (mlx.img_x) * mlx.j, mlx.img_y * mlx.i);
	else if (av == 'E')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.exit, (mlx.img_x) * mlx.j, mlx.img_y * mlx.i);
	else if (av == '1')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.wall, (mlx.img_x) * mlx.j, mlx.img_y * mlx.i);
	// else
	// 	ft_putstr_fd("Error");
}

void	path_prot(char **av)
{
	t_data	son;

	son.i = 0;
	son.b = 0;
	son.k = 0;
	while (av[son.i])
	{
		son.j = 0;
		while (av[son.i][son.j])
		{
			if (av[son.i][son.j] == 'P')
				son.k++;
			else if (av[son.i][son.j] == 'E')
				son.b++;
			if (son.k > 1)
				ft_putstr_fd("more than 1 player");
			if (son.b > 1)
				ft_putstr_fd("more than 1 exit");
			son.j++;
		}
		son.i++;
	}
}

void	put_image(t_mlx mlx)
{
	mlx.img = mlx_xpm_file_to_image(mlx.mlx, mlx.path, &mlx.img_x, &mlx.img_y);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, (mlx.img_x) * mlx.j, mlx.img_y * mlx.i);
}

void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(1);
}

int	ft_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}
