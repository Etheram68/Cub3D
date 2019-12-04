/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:12:23 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 14:11:46 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	draw(t_map *map, int x)
{
	int		len;
	int		range_start;
	int		range_end;

	len = (int)(map->w_height / RAY.dist);
	range_start = -len / 2 + map->w_height / 2;
	if (range_start < 0)
		range_start = 0;
	range_end = len / 2 + map->w_height / 2;
	if (range_end >= map->w_height)
		range_end = map->w_height - 1;
	draw_line(map, x, range_start, range_end);
}

void	rayon_dist(t_map *map)
{
	while (RAY.hit == 0)
	{
		if (RAY.side.x < RAY.side.y)
		{
			RAY.side.x += RAY.delta.x;
			RAY.map.x += RAY.step.x;
			RAY.hit_side = 0;
		}
		else
		{
			RAY.side.y += RAY.delta.y;
			RAY.map.y += RAY.step.y;
			RAY.hit_side = 1;
		}
		if (map->map[RAY.map.x][RAY.map.y] > 0)
		{
			RAY.hit = 1;
			if (RAY.hit_side == 0)
				RAY.dist = (RAY.map.x - RAY.pos.x + (1 - RAY.step.x)
								/ 2) / RAY.dir.x;
			else
				RAY.dist = (RAY.map.y - RAY.pos.y + (1 - RAY.step.y)
								/ 2) / RAY.dir.y;
		}
	}
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
		RAY.step.y = 1;
		RAY.side.y = ((int)RAY.pos.y + 1 - RAY.pos.y) * RAY.delta.y;
	}
}

void	init_rayon(t_map *map, int x)
{
	RAY.map.x = (int)RAY.pos.x;
	RAY.map.y = (int)RAY.pos.y;
	RAY.cam = 2 * x / (double)map->w_width - 1;
	RAY.dir.x = PLAYER.dir.x + PLAYER.plane.x * RAY.cam;
	RAY.dir.y = PLAYER.dir.y + PLAYER.plane.y * RAY.cam;
	RAY.delta.x = fabs(1 / RAY.dir.x);
	RAY.delta.y = fabs(1 / RAY.dir.y);
	RAY.hit = 0;
	RAY.dist = -1;
	RAY.hit_side = -1;
}

int		ft_raycasting(t_map *map)
{
	int				x;

	x = -1;
	RAY.pos.x = PLAYER.pos.x;
	RAY.pos.y = PLAYER.pos.y;
	while (++x < map->w_width)
	{
		init_rayon(map, x);
		rayon_side(map);
		rayon_dist(map);
		draw(map, x);
	}
	return (1);
}
