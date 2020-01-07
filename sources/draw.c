/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:11:42 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:49:02 by frfrey      ###    #+. /#+    ###.fr     */
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
	if (map->ray.hit_side == 1)
	{
		if ((map->ray.step.y == -1 && map->ray.step.x == -1) ||
			(map->ray.step.y == 1 && map->ray.step.x == -1))
			return (3);
		if ((map->ray.step.y == -1 && map->ray.step.x == 1) ||
			(map->ray.step.y == 1 && map->ray.step.x == 1))
			return (2);
	}
	if ((map->ray.step.y == -1 && map->ray.step.x == -1) ||
		(map->ray.step.y == -1 && map->ray.step.x == 1))
		return (0);
	return (1);
}

void			calc_wall(t_map *map, int i)
{
	if (map->ray.hit_side == 0)
		map->wall.wall = map->player.pos.x + map->ray.dist * map->ray.dir.x;
	else
		map->wall.wall = map->player.pos.y + map->ray.dist * map->ray.dir.y;
	map->wall.wall -= floor(map->wall.wall);
	map->wall.tex_x = (int)(map->wall.wall * (double)(64));
	if (map->ray.hit_side == 0 && map->player.dir.y > 0)
		map->wall.tex_x = 64 - map->wall.tex_x - 1;
	if (map->ray.hit_side == 1 && map->player.dir.x < 0)
		map->wall.tex_x = 64 - map->wall.tex_x - 1;
	map->wall.tex_y = (((i * 256 - map->w_height * 128 + map->ray.len * 128)
				* 64) / map->ray.len) / 256;
}

void			dist_wall(t_map *map)
{
	map->ray.hit = 1;
	if (map->ray.hit_side == 0)
		map->ray.dist = (map->ray.map.y - map->ray.pos.y + (1 - map->ray.step.y)
						/ 2) / map->ray.dir.y;
	else
		map->ray.dist = (map->ray.map.x - map->ray.pos.x + (1 - map->ray.step.x)
						/ 2) / map->ray.dir.x;
}

void			draw_line(t_map *map, int x)
{
	int				i;
	int				p;
	unsigned long	c;

	i = -1;
	p = get_texture(map);
	while (++i < map->ray.start)
		draw_wall(map, x, i, map->ceil);
	i--;
	while (++i <= map->ray.end && i < map->w_height)
	{
		calc_wall(map, i);
		c = map->tex[p].data[64 * map->wall.tex_y + map->wall.tex_x];
		draw_wall(map, x, i, c);
	}
	i--;
	while (++i < map->w_height)
		draw_wall(map, x, i, map->floor);
}
