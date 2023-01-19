/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:51:43 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/19 14:36:21 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *path_find(char av, t_data img, int *i)
{
    if (av == 'P')
    {
        img.path = "img/ghost_f.xpm";
        
        *i = *i + 1;
    }
    else if (av == '0')
        img.path = "img/floor.xpm";
    else if (av == 'C')
        img.path = "img/collect_f.xpm";
    else if (av == 'E')
        img.path = "img/exit.xpm";
    else if (av == '1')
        img.path = "img/wall.xpm";
    // else
	// {
    //     write(1, "Error", 5);
	// 	exit(1);
	// }
    return(img.path);
}

void path_prot(char **av)
{
	int_data son;

    son.i = 0;
    son.b = 0;
    son.k = 0;
    while(av[son.i])
    {
        son.j = 0;
        while(av[son.i][son.j])
        {
            if (av[son.i][son.j] == 'P')
                son.k++;
            else if (av[son.i][son.j] == 'E')
                son.b++;
            if(son.k > 1)
            {
                write(2, "more than 1 player", 18);
				son.k = 0;
                exit(1);
            }
            if(son.b > 1)
            {
                write(2, "more than 1 exit", 18);
				son.b = 0;
                exit(1);
            }
            son.j++;
        }
        son.i++;
    }
}

void    put_image(mlx_data mlx, t_data img, int_data data)
{
	    img.img = mlx_xpm_file_to_image(mlx.mlx, img.path, &img.x, &img.y);
	    mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, (img.x) * data.j, img.y * data.i);
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

int	ft_exit(mlx_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}
