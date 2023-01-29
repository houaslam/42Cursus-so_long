/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:08:54 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/29 17:14:53 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h" 

void	arg_prot(t_mlx *mlx, char **av)
{
	char	*path;

	if (!ft_strlen(av[1]))
		ft_putstr_fd("ADD A MAP!!");
	if (ft_strnstr(av[1], ".ber") == 0)
		ft_putstr_fd("MAP SHOULD END WITH WITH '.ber'");
	path = ft_join("maps/", av[1]);
	mlx->fd = open(path, O_RDONLY);
	free(path);
	if (mlx->fd < 0)
		ft_putstr_fd("MAP COULDN T BE OPENED");
}

void	element_prot(char **av, t_mlx *mlx)
{
	t_data	son;

	son.i = 0;
	son.k = 0;
	son.b = 0;
	mlx->collect_num = 0;
	while (av[son.i])
	{
		son.j = 0;
		while (av[son.i][son.j])
		{
			if (av[son.i][son.j] == 'P')
				son.k++;
			else if (av[son.i][son.j] == 'E')
				son.b++;
			else if (av[son.i][son.j] == 'C')
				mlx->collect_num++;
			if (son.k > 1 || son.b > 1)
				ft_putstr_fd("more than 1 PLAYER / EXIT");
			son.j++;
		}
		son.i++;
	}
	if (mlx->collect_num < 1 || son.k == 0 || son.b == 0)
		ft_putstr_fd("less than 1 collectable/ exit/player");
}

void	map_prot(t_mlx mlx)
{
	t_data	data;

	data.i = 0;
	data.j = 0;
	data.len = ft_strlen(mlx.ptr[0]) - 1;
	while (mlx.ptr[data.i])
	{
		data.j = 0;
		while (mlx.ptr[data.i][data.j])
		{
			if (ft_strlen(mlx.ptr[data.i]) - 1 != data.len)
				ft_putstr_fd("maps is invalid");
			if (mlx.ptr[0][data.j] != '1' || \
			mlx.ptr[data.i][0] != '1' || mlx.ptr[data.i][data.len] != '1')
				ft_putstr_fd("maps is invalid");
			data.j++;
		}
		data.i++;
	}
	map_prot2(mlx, data);
}

void	map_prot2(t_mlx mlx, t_data data)
{
	data.j = 0;
	data.i--;
	while (mlx.ptr[data.i][data.j])
	{
		if (mlx.ptr[data.i][data.j] != '1')
			ft_putstr_fd("maps is invalid");
		data.j++;
	}
	if (data.i == data.j - 1)
		ft_putstr_fd("map should be rectangulare");
}
