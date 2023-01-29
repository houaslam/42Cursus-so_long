/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:51:43 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/29 17:12:54 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	init(t_mlx *mlx)
{
	mlx->ghost_f = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/ghost_f.xpm", &mlx->p_x, &mlx->p_y);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/before.xpm", &mlx->img_x, &mlx->img_y);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/wall.xpm", &mlx->img_x, &mlx->img_y);
	mlx->floor = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/floor.xpm", &mlx->img_x, &mlx->img_y);
	mlx->collect_f = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/collect_f.xpm", &mlx->img_x, &mlx->img_y);
	mlx->ghost_l = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/ghost_l.xpm", &mlx->img_x, &mlx->img_y);
	mlx->ghost_b = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/ghost_b.xpm", &mlx->img_x, &mlx->img_y);
	mlx->ghost_r = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/ghost_r.xpm", &mlx->img_x, &mlx->img_y);
	mlx->exit2 = mlx_xpm_file_to_image(mlx->mlx \
	, "textures/after.xpm", &mlx->img_x, &mlx->img_y);
}

void	read_data1(t_mlx *mlx)
{
	char	*help;

	mlx->win_y = 1;
	mlx->fin = NULL;
	help = get_next_line(mlx->fd);
	while (1)
	{
		mlx->fin = ft_strjoin(mlx->fin, help);
		free(help);
		help = get_next_line(mlx->fd);
		if (help == NULL)
			break ;
		mlx->win_y++;
	}
	mlx->ptr = ft_split(mlx->fin, '\n');
	free(mlx->fin);
}

void	put_element(char av, t_mlx *mlx)
{
	if (av == 'P')
		mlx_put_image_to_window(mlx->mlx, \
	mlx->mlx_win, mlx->ghost_f, mlx->img_x * mlx->p_x, mlx->img_y * mlx->p_y);
	else if (av == '0')
		mlx_put_image_to_window(mlx->mlx, \
		mlx->mlx_win, mlx->floor, (mlx->img_x) * mlx->y, mlx->img_y * mlx->x);
	else if (av == 'E')
	{
		mlx_put_image_to_window(mlx->mlx, \
		mlx->mlx_win, mlx->exit, (mlx->img_x) * mlx->y, mlx->img_y * mlx->x);
		mlx->e_x = mlx->x;
		mlx->e_y = mlx->y;
	}
	else if (av == '1')
		mlx_put_image_to_window(mlx->mlx, \
		mlx->mlx_win, mlx->wall, (mlx->img_x) * mlx->y, mlx->img_y * mlx->x);
	else if (av == 'C')
		mlx_put_image_to_window(mlx->mlx, \
	mlx->mlx_win, mlx->collect_f, mlx->img_x * mlx->y, mlx->img_y * mlx->x);
	else
		ft_putstr_fd("Another element");
}

int	ft_exit(t_mlx *mlx)
{
	ft_printf("GAME OVER !!");
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

void	put1_image(t_mlx *mlx, void *texture, int y, int x)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
	texture, (mlx->img_x) * x, mlx->img_y * y);
}
