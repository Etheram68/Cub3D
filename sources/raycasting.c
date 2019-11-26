/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:12:23 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 15:34:48 by frfrey      ###    #+. /#+    ###.fr     */
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

void	rayon_side(t_map *map)
{
	if (RAY.dir.x < 0)
	{
		RAY.step.x = -1;
		RAY.side.x = (RAY.pos.x - (int)RAY.pos.x) * RAY.delta.x;
	}
	else
	{
		RAY.step.x = 1;
		RAY.side.x = ((int)RAY.pos.x + 1 - RAY.pos.x) * RAY.delta.x;
	}
	if (RAY.dir.y < 0)
	{
		RAY.step.y = -1;
		RAY.side.y = (RAY.pos.y - (int)RAY.pos.y) * RAY.delta.y;
	}
	else
	{
		RAY.step = 1;
		RAY.side.y = ((int)RAY.pos.y + 1 - RAY.pos.y) * RAY.delta.y;
	}
}

void	init_rayon(t_map *map, int x)
{
	RAY.map.x = (int)RAY.pos.x;
	RAY.map.y = (int)RAY.pos.y;
	RAY.cam = (2 * x) / ((double)map->w_width - 1);
	RAY.dir.x = RAY.dir.x + PLAYER.plane.x * RAY.cam;
	RAY.dir.y = PLAYER.dir.y + PLAYER.plane.y * RAY.cam;
	RAY.delta.x = sqrt(1 + (RAY.dir.y * RAY.dir.y) /
									(RAY.dir.x * RAY.dir.x));
	RAY.delta.y = sqrt(1 + (RAY.dir.x * RAY.dir.x) /
									(RAY.dir.y * RAY.dir.y));
	RAY.hit = 0;
	RAY.dist = -1;
	RAY.hit_side = -1;
}

int		raycasting(t_map *map)
{
	int		x;

	x = 0;
	RAY.pos.x = PLAYER.pos.x;
	RAY.pos.y = PLAYER.pos.y;
	while (x < map->w_width)
	{
		init_rayon(map, x);
		rayon_side(map);
	}
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
	mlx_loop_hook(map->id.mlx, raycasting, map);
	mlx_key_hook(map->id.windows, deal_key, map);
	mlx_hook(map->id.windows, 17, 0, try, map);
	mlx_loop(map->id.mlx);
}
