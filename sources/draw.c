/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:11:42 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 14:19:42 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void			draw_pixel(t_map *map, int x, int y, unsigned int c)
{
	int		i;

	i = x + (y * map->w_width);
	map->id.data[i] = c;
}

unsigned int	get_texture(t_map *map)
{
	if (RAY.hit_side == 1)
	{
		if ((RAY.step.y == -1 && RAY.step.x == -1) ||
			(RAY.step.y == 1 && RAY.step.x == -1))
			return (1);
		if ((RAY.step.y == -1 && RAY.step.x == 1) ||
			(RAY.step.y == 1 && RAY.step.x == 1))
			return (2);
	}
	if ((RAY.step.y == -1 && RAY.step.x == -1) ||
		(RAY.step.y == -1 && RAY.step.x == 1))
		return (0);
	return (3);
}

void			draw_wall(t_map *map, int i)
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
	WALL.tex_y = (((i * 256 - 1080 * 128 + RAY.len * 128)
				* 64) / RAY.len) / 256;
}

void			draw_line(t_map *map, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	i = -1;
	c = get_texture(map);
	while (++i < start)
		draw_pixel(map, x, i, map->ceil);
	i--;
	while (++i <= end && i < map->w_height)
	{
		draw_wall(map, i);
		draw_pixel(map, x, i, map->tex[c].data[64 * WALL.tex_y
					+ WALL.tex_x]);
	}
	i--;
	while (++i < map->w_height)
		draw_pixel(map, x, i, map->floor);
}
