/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 15:02:56 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 20:24:38 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void			dist_sprite(t_map *map, int y, int x)
{
	if (map->spr_i > 50)
		print_error("Error:\nYou have more sprite on map\n", map);
	map->spr[map->spr_i].pos.x = x + 0.5;
	map->spr[map->spr_i].pos.y = y + 0.5;
	map->spr[map->spr_i].type = map->map[y][x];
	map->spr_i++;
}

void			draw_sprite(t_map *map, int y, unsigned int c)
{
	int		i;

	i = SPRITE.save + (y * map->w_width);
	map->id.data[i] = c;
}

void			draw_line_spr(t_map *map)
{
	int				y;
	int				p;
	unsigned int	c;

	p = map->spr[map->spr_i].type;
	c = 0;
	y = SPRITE.start.y;
	while (y < SPRITE.end.y)
	{
		SPRITE.tex.y = (((y * 256 - map->w_height * 128 +
					SPRITE.s_height * 128) * 64) / SPRITE.s_height) / 256;
		c = map->tex[4].data[64 * SPRITE.tex.y + SPRITE.tex.x];
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
		SPRITE.save = SPRITE.start.x;
		while (SPRITE.save < SPRITE.end.x)
		{
			SPRITE.tex.x = (int)(256 * (SPRITE.save - (-SPRITE.s_width /
					2 + SPRITE.screen)) * 64 / SPRITE.s_width) / 256;
			if (SPRITE.form.y > 0 && SPRITE.save > 0
					&& SPRITE.save < map->w_width &&
						SPRITE.form.y < size[SPRITE.save])
				draw_line_spr(map);
			SPRITE.save++;
		}
		i++;
	}
}
