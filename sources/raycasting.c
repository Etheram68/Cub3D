/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:12:23 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 19:36:22 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		changecolor(t_map *map)
{
	int x = 0;
	int y = 0;
	int *data;
	int bits = 0;
	int size = 0;
	int endian = 0;

	data = (int *)mlx_get_data_addr(map->id.image, &bits, &size, &endian);
	while (y < map->w_width)
	{
		x = 0;
		while (x < map->w_height)
		{
			data[y * map->w_height + x] = map->id.color + x;
			x++;
		}
		y++;
		map->id.color = map->id.color + 1;
	}
	mlx_put_image_to_window(map->id.mlx, map->id.windows, map->id.image, 0, 0);
	return (1);
}

int		print_wall(t_map *map)
{

	return (1);
}

void	ft_raycasting(t_map *map)
{
	if (!(map->id.mlx = mlx_init()))
		print_error("Error:\nWhen you init id mlx\n");
	if (!(map->id.windows = mlx_new_window(map->id.mlx,
			map->w_width, map->w_height, "Cube3D")))
		print_error("Eroor:\nWhen you initialise windows\n");
	map->id.image = mlx_new_image(map->id.mlx, 1920, 1080);
	mlx_loop_hook(map->id.mlx, print_wall, map);
	mlx_key_hook(map->id.windows, deal_key, map);
	mlx_hook(map->id.windows, 17, 0, try, map);
	mlx_loop(map->id.mlx);
}
