/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:11:42 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 17:30:34 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void			draw_wall(t_map *map, int x, int y, unsigned int c)
{
	int				i;

	i = x + (y * map->w_width);
	map->id.data[i] = c;
}

unsigned int	get_texture(t_map *map)
{
	if (RAY.hit_side == 1)
	{
		if ((RAY.step.y == -1 && RAY.step.x == -1) ||
			(RAY.step.y == 1 && RAY.step.x == -1))
			return (3);
		if ((RAY.step.y == -1 && RAY.step.x == 1) ||
			(RAY.step.y == 1 && RAY.step.x == 1))
			return (2);
	}
	if ((RAY.step.y == -1 && RAY.step.x == -1) ||
		(RAY.step.y == -1 && RAY.step.x == 1))
		return (0);
	return (1);
}

void			calc_wall(t_map *map, int i)
{
	if (RAY.hit_side == 0)
		WALL.wall = PLAYER.pos.x + RAY.dist * RAY.dir.x;
	else
		WALL.wall = PLAYER.pos.y + RAY.dist * RAY.dir.y;
	WALL.wall -= floor(WALL.wall);
	WALL.tex_x = (int)(WALL.wall * (double)(64));
	if (RAY.hit_side == 0 && PLAYER.dir.y > 0)
		WALL.tex_x = 64 - WALL.tex_x - 1;
	if (RAY.hit_side == 1 && PLAYER.dir.x < 0)
		WALL.tex_x = 64 - WALL.tex_x - 1;
	WALL.tex_y = (((i * 256 - map->w_height * 128 + RAY.len * 128)
				* 64) / RAY.len) / 256;
}

void			dist_wall(t_map *map)
{
	RAY.hit = 1;
	if (RAY.hit_side == 0)
		RAY.dist = (RAY.map.y - RAY.pos.y + (1 - RAY.step.y)
						/ 2) / RAY.dir.y;
	else
		RAY.dist = (RAY.map.x - RAY.pos.x + (1 - RAY.step.x)
						/ 2) / RAY.dir.x;
}

void			draw_line(t_map *map, int x)
{
	int				i;
	int				p;
	unsigned long	c;

	i = -1;
	p = get_texture(map);
	while (++i < RAY.start)
		draw_wall(map, x, i, map->ceil);
	i--;
	while (++i <= RAY.end && i < map->w_height)
	{
		calc_wall(map, i);
		c = map->tex[p].data[64 * WALL.tex_y + WALL.tex_x];
		draw_wall(map, x, i, c);
	}
	i--;
	while (++i < map->w_height)
		draw_wall(map, x, i, map->floor);
}
