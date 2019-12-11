/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:11:42 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 20:00:34 by frfrey      ###    #+. /#+    ###.fr     */
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
	if (map->ray.hit_side == 1)
	{
		if ((map->ray.step.y == -1 && map->ray.step.x == -1) ||
			(map->ray.step.y == 1 && map->ray.step.x == -1))
			return (1);
		if ((map->ray.step.y == -1 && map->ray.step.x == 1) ||
			(map->ray.step.y == 1 && map->ray.step.x == 1))
			return (2);
	}
	if ((map->ray.step.y == -1 && map->ray.step.x == -1) ||
		(map->ray.step.y == -1 && map->ray.step.x == 1))
		return (0);
	return (3);
}

void			draw_line(t_map *map, int x, int start, int end)
{
	int				i;
	unsigned int	c;
	int				text_x;
	int				text_y;
	double			wall_x;
	int				line_heigth;

	i = -1;
	c = get_texture(map);
	line_heigth = (int)(map->w_height / RAY.dist);
	while (++i < start)
	{
		draw_pixel(map, x, i, map->ceil);
	}
	i--;
	while (++i <= end && i < map->w_height - 1)
	{
			if (RAY.hit_side == 0)
				wall_x = PLAYER.pos.x + RAY.dist * RAY.dir.x;
			else
				wall_x = PLAYER.pos.y + RAY.dist * RAY.dir.y;
			wall_x -= floor(wall_x);
			text_x = (int)(wall_x * (double)(64));
			if (RAY.hit_side == 0 && PLAYER.dir.y > 0)
				text_x = 64 - text_x - 1;
			if (RAY.hit_side == 1 && PLAYER.dir.x < 0)
				text_x = 64 - text_x - 1;
			text_y = (((i * 256 - 1080 * 128 + line_heigth * 128) * 64) / line_heigth) / 256;
			draw_pixel(map, x, i, map->tex[c].data[64 * text_y + text_x]);
	}
	i--;
	while (++i < map->w_height - 1)
		draw_pixel(map, x, i, map->floor);
}
