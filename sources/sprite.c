/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 15:02:56 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 16:07:15 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void		dist_sprite(t_map *map, t_sprite *spr)
{
	RAY.sprite = 1;
	spr[map->spr_i].pos.x = RAY.map.x + 0.5;
	spr[map->spr_i].pos.y = RAY.map.y + 0.5;
	spr[map->spr_i].type = map->map[RAY.map.y][RAY.map.x];
	spr[map->spr_i].dist = ((PLAYER.pos.y - spr[map->spr_i].pos.y)
					* (PLAYER.pos.y - spr[map->spr_i].pos.y) +
						(PLAYER.pos.x - spr[map->spr_i].pos.x)
							* (PLAYER.pos.x - spr[map->spr_i].pos.x));
	map->spr_i += 1;
}

void			draw_sprite(t_map *map, int x, int y, unsigned int c)
{
	int		i;

	i = x + (y * map->w_width);
	if (c != 0)
		map->id.data[i] = c;
}

void			calc_sprite(t_map *map, int i)
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

void			draw_line_spr(t_map *map, int x, t_sprite *spr)
{
	int				i;
	int				p;
	unsigned int	c;

	i = -1;
	p = 4;
	(void)spr;
	c = 0;
	i = RAY.start;
	while (++i <= RAY.end && i < map->w_height)
	{
		calc_sprite(map, i);
		c = map->tex[p].data[64 * WALL.tex_y + WALL.tex_x];
		draw_sprite(map, x, i, c);
	}
}

void	draw_spr(t_map *map, int x, t_sprite *spr)
{
	RAY.len = (int)(map->w_height / RAY.dist);
	RAY.start = -RAY.len / 2 + map->w_height / 2;
	if (RAY.start < 0)
		RAY.start = 0;
	RAY.end = RAY.len / 2 + map->w_height / 2;
	if (RAY.end >= map->w_height)
		RAY.end = map->w_height - 1;
	draw_line_spr(map, x, spr);
}
