/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 15:02:56 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:48:43 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void			dist_sprite(t_map *map, int y, int x)
{
	if (map->spr_i > 49)
		print_error("Error:\nYou have more sprite on map\n", map);
	map->spr[map->spr_i].pos.x = x + 0.5;
	map->spr[map->spr_i].pos.y = y + 0.5;
	map->spr[map->spr_i].type = map->map[y][x];
	map->spr_i++;
}

void			draw_sprite(t_map *map, int y, unsigned int c)
{
	int		i;

	i = map->csp.save + (y * map->w_width);
	map->id.data[i] = c;
}

void			draw_line_spr(t_map *map)
{
	int				y;
	int				p;
	unsigned int	c;

	p = map->spr[map->spr_i].type;
	c = 0;
	y = map->csp.start.y;
	while (y < map->csp.end.y)
	{
		map->csp.tex.y = (((y * 256 - map->w_height * 128 +
					map->csp.s_height * 128) * 64)
						/ map->csp.s_height) / 256;
		c = map->tex[4].data[64 * map->csp.tex.y + map->csp.tex.x];
		if (c != 0)
			draw_sprite(map, y, c);
		y++;
	}
}

void			draw_spr(t_map *map, double *size)
{
	int				i;

	i = 0;
	ft_calc_dist_spr(map);
	while (i < map->spr_i)
	{
		calc_sprite(map, i);
		map->csp.save = map->csp.start.x;
		while (map->csp.save < map->csp.end.x)
		{
			map->csp.tex.x = (int)(256 *
				(map->csp.save - (-map->csp.s_width /
					2 + map->csp.screen)) * 64 / map->csp.s_width) / 256;
			if (map->csp.form.y > 0 && map->csp.save > 0
					&& map->csp.save < map->w_width &&
						map->csp.form.y < size[map->csp.save])
				draw_line_spr(map);
			map->csp.save++;
		}
		i++;
	}
}
