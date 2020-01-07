/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:12:23 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:42:52 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	draw(t_map *map, int x)
{
	map->ray.len = (int)(map->w_height / map->ray.dist);
	map->ray.start = -map->ray.len / 2 + map->w_height / 2;
	if (map->ray.start < 0)
		map->ray.start = 0;
	map->ray.end = map->ray.len / 2 + map->w_height / 2;
	if (map->ray.end >= map->w_height)
		map->ray.end = map->w_height - 1;
	draw_line(map, x);
}

void	rayon_dist(t_map *map)
{
	while (map->ray.hit == 0)
	{
		if (map->ray.side.y < map->ray.side.x)
		{
			map->ray.side.y += map->ray.delta.y;
			map->ray.map.y += map->ray.step.y;
			map->ray.hit_side = 0;
		}
		else
		{
			map->ray.side.x += map->ray.delta.x;
			map->ray.map.x += map->ray.step.x;
			map->ray.hit_side = 1;
		}
		if (map->map[map->ray.map.y][map->ray.map.x] == 1)
			dist_wall(map);
	}
}

void	rayon_side(t_map *map)
{
	if (map->ray.dir.y < 0)
	{
		map->ray.step.y = -1;
		map->ray.side.y = (map->ray.pos.y - (int)map->ray.pos.y)
			* map->ray.delta.y;
	}
	else
	{
		map->ray.step.y = 1;
		map->ray.side.y = ((int)map->ray.pos.y + 1 - map->ray.pos.y)
			* map->ray.delta.y;
	}
	if (map->ray.dir.x < 0)
	{
		map->ray.step.x = -1;
		map->ray.side.x = (map->ray.pos.x - (int)map->ray.pos.x)
			* map->ray.delta.x;
	}
	else
	{
		map->ray.step.x = 1;
		map->ray.side.x = ((int)map->ray.pos.x + 1 - map->ray.pos.x)
			* map->ray.delta.x;
	}
}

void	init_rayon(t_map *map, int x)
{
	map->ray.map.y = (int)map->ray.pos.y;
	map->ray.map.x = (int)map->ray.pos.x;
	map->ray.cam = 2 * x / (double)map->w_width - 1;
	map->ray.dir.x = map->player.dir.x + map->player.plane.x * map->ray.cam;
	map->ray.dir.y = map->player.dir.y + map->player.plane.y * map->ray.cam;
	map->ray.delta.x = fabs(1 / map->ray.dir.x);
	map->ray.delta.y = fabs(1 / map->ray.dir.y);
	map->ray.hit = 0;
	map->ray.dist = -1;
	map->ray.hit_side = -1;
	map->ray.sprite = 0;
}

int		ft_raycasting(t_map *map)
{
	int				x;
	double			size[map->w_width];

	x = -1;
	map->ray.pos.x = map->player.pos.x;
	map->ray.pos.y = map->player.pos.y;
	while (++x < map->w_width)
	{
		init_rayon(map, x);
		rayon_side(map);
		rayon_dist(map);
		size[x] = map->ray.dist;
		draw(map, x);
	}
	draw_spr(map, size);
	return (1);
}
