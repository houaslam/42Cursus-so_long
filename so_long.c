/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:22:45 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/19 14:34:12 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moves(int keycode, mlx_data *data)
{
	if (keycode == 53)
		ft_exit(data);
    else if (keycode == left || keycode == arrow_left)
		ft_exit(data);
    else if (keycode == up || keycode == arrow_up)
		ft_exit(data);
    else if (keycode == down || keycode == arrow_down)
		ft_exit(data);
    else if (keycode == right || keycode == arrow_right)
		ft_exit(data);
	return (0);
}

void make_path(mlx_data mlx, t_data img, char **ptr)
{
	int_data data;

    data.i = 0;
    data.k = 0;
    while(ptr[data.i])
    {
       	data.j = 0;
        while(ptr[data.i][data.j])
        {
            img.path = "img/floor.xpm";
            put_image(mlx, img, data);
            img.path = path_find(ptr[data.i][data.j], img, &data.k);
            printf("%s\n", img.path);
            put_image(mlx, img, data);
            data.j++;
        }
        data.i++;
    }
    path_prot(ptr);
}

char **read_data(mlx_data *mlx, char **av)
{
    char **ptr;
    
    ptr = malloc(sizeof(char **));
    mlx->fd = open(av[1], O_RDONLY);
    if(mlx->fd < 0)
        ft_putstr_fd("map Error");
    ptr[mlx->size_y] = get_next_line(mlx->fd);
    while(ptr[mlx->size_y])
    {
        mlx->size_x = 0;
        while(ptr[mlx->size_y][mlx->size_x])
            mlx->size_x++;
        mlx->size_y++;
        ptr[mlx->size_y] = get_next_line(mlx->fd);
    }
    return(ptr);
}


int main(int ac ,char **av)
{
    mlx_data mlx;
    t_data	img;
    char **ptr;

    (void)ac;
    img.x = 0;
    img.y = 0;
    mlx.mlx = mlx_init();
	ptr = read_data(&mlx, av);
    printf("%d\n", mlx.size_x);
    printf("%d\n", mlx.size_y);
    mlx.size_x--;
	mlx.mlx_win = mlx_new_window(mlx.mlx, mlx.size_x * 40, mlx.size_y * 40, "so_long");
    img.img = mlx_new_image(mlx.mlx, 40, 40);
    make_path(mlx, img, ptr);
	mlx_hook(mlx.mlx_win, 17, 0, ft_exit, &mlx);
	mlx_key_hook(mlx.mlx_win, ft_moves, &mlx);
    // ft_freestr(ptr, mlx.size_y);
	mlx_loop(mlx.mlx);
}