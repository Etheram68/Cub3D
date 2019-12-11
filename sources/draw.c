/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:11:42 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 13:42:45 by frfrey      ###    #+. /#+    ###.fr     */
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
			return (0x990066);
		if ((map->ray.step.y == -1 && map->ray.step.x == 1) ||
			(map->ray.step.y == 1 && map->ray.step.x == 1))
			return (0x0099FF);
	}
	if ((map->ray.step.y == -1 && map->ray.step.x == -1) ||
		(map->ray.step.y == -1 && map->ray.step.x == 1))
		return (0);
	return (0xCC6600);
}

void			draw_line(t_map *map, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	i = -1;
	c = get_texture(map);
	while (++i < start)
	{
		draw_pixel(map, x, i, map->ceil);
	}
	while (++i <= end && i < map->w_height)
	{
		if (c == 0)
		{
			draw_pixel(map, x, i, map->tex[0].data[i]);
		}
		else
			draw_pixel(map, x, i, c);
	}
	while (++i < map->w_height)
		draw_pixel(map, x, i, map->floor);
}
