/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 15:02:56 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 18:37:20 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void			dist_sprite(t_map *map, t_sprite *spr)
{
	spr[map->spr_i].pos.x = RAY.map.x;
	spr[map->spr_i].pos.y = RAY.map.y;
	spr[map->spr_i].type = map->map[RAY.map.y][RAY.map.x];
	map->spr_i += 1;
}

void			draw_sprite(t_map *map, int x, int y, unsigned int c)
{
	int		i;

	i = x + (y * map->w_width);
	map->id.data[i] = c;
}

void			draw_line_spr(t_map *map, int x, t_sprite *spr)
{
	int				y;
	int				p;
	unsigned int	c;

	p = spr[map->spr_i].type;
	c = 0;
	y = SPRITE.start.y;
	while (y < SPRITE.end.y)
	{
		SPRITE.tex.y = (((y * 256 - map->w_height * 128 +
					SPRITE.s_height * 128) * 64) / SPRITE.s_height) / 256;
		c = map->tex[4].data[64 * SPRITE.tex.y + SPRITE.tex.x];
		if (c != 0)
			draw_sprite(map, x, y, c);
		y++;
	}
}

void			calc_sprite(t_map *map, int i, t_sprite *spr)
{
	SPRITE.sprite.x = spr[i].pos.x - PLAYER.pos.x;
	SPRITE.sprite.y = spr[i].pos.y - PLAYER.pos.y;
	SPRITE.multi = 1.0 / (PLAYER.plane.x * PLAYER.dir.y -
					PLAYER.dir.x * PLAYER.plane.y);
	SPRITE.form.x = SPRITE.multi * (PLAYER.dir.y * SPRITE.sprite.x -
					PLAYER.dir.x * SPRITE.sprite.y);
	SPRITE.form.y = SPRITE.multi * (-PLAYER.plane.y * SPRITE.sprite.x +
					PLAYER.plane.x * SPRITE.sprite.y);
	SPRITE.screen.x = (int)((map->w_width / 2) *
					(1 + SPRITE.form.x / SPRITE.form.y));
	SPRITE.s_height = abs((int)(map->w_height / (SPRITE.form.y)));
	SPRITE.start.y = -SPRITE.s_height / 2 + map->w_height / 2;
	if (SPRITE.start.y < 0)
		SPRITE.start.y = 0;
	SPRITE.end.y = SPRITE.s_height / 2 + map->w_height / 2;
	if (SPRITE.end.y >= map->w_height)
		SPRITE.end.y = map->w_height - 1;
	SPRITE.s_width = abs((int)(map->w_height / (SPRITE.form.y)));
	SPRITE.start.x = -SPRITE.s_width / 2 + SPRITE.screen.x;
	if (SPRITE.start.x < 0)
		SPRITE.start.x = 0;
	SPRITE.end.x = SPRITE.s_width / 2 + SPRITE.screen.x;
	if (SPRITE.end.x >= map->w_width)
		SPRITE.end.x = map->w_width - 1;
	SPRITE.save = SPRITE.start.x;
}

void			draw_spr(t_map *map, int x, t_sprite *spr)
{
	int				i;

	i = map->spr_i - 1;
	while (i >= 0)
	{
		calc_sprite(map, i, spr);
		while (SPRITE.save < SPRITE.end.x)
		{
			SPRITE.tex.x = (int)(256 * (SPRITE.save - (-SPRITE.s_width /
					2 + SPRITE.screen.x)) * 64 / SPRITE.s_width) / 256;
			if (SPRITE.form.y > 0 && SPRITE.save > 0
					&& SPRITE.save < map->w_width)
				draw_line_spr(map, x, spr);
			SPRITE.save++;
		}
		i--;
	}
}
