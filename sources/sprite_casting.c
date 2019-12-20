/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_casting.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 14:13:34 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 17:42:46 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	calc_sprite(t_map *map, int i)
{
	SPRITE.sprite.x = map->spr[map->order[i]].pos.x - PLAYER.pos.x;
	SPRITE.sprite.y = map->spr[map->order[i]].pos.y - PLAYER.pos.y;
	SPRITE.multi = 1 / (PLAYER.plane.y * PLAYER.dir.x -
					PLAYER.dir.y * PLAYER.plane.x);
	SPRITE.form.x = SPRITE.multi * (PLAYER.dir.x * SPRITE.sprite.y -
					PLAYER.dir.y * SPRITE.sprite.x);
	SPRITE.form.y = SPRITE.multi * (-PLAYER.plane.x * SPRITE.sprite.y +
					PLAYER.plane.y * SPRITE.sprite.x);
	SPRITE.screen = (int)((map->w_width / 2) *
					(1 + SPRITE.form.x / SPRITE.form.y));
	SPRITE.s_height = abs((int)(map->w_height / (SPRITE.form.y)));
	SPRITE.start.y = -SPRITE.s_height / 2 + map->w_height / 2;
	if (SPRITE.start.y < 0)
		SPRITE.start.y = 0;
	SPRITE.end.y = SPRITE.s_height / 2 + map->w_height / 2;
	if (SPRITE.end.y >= map->w_height)
		SPRITE.end.y = map->w_height - 1;
	SPRITE.s_width = abs((int)(map->w_height / (SPRITE.form.y)));
	SPRITE.start.x = -SPRITE.s_width / 2 + SPRITE.screen;
	if (SPRITE.start.x < 0)
		SPRITE.start.x = 0;
	SPRITE.end.x = SPRITE.s_width / 2 + SPRITE.screen;
	if (SPRITE.end.x >= map->w_width)
		SPRITE.end.x = map->w_width - 1;
}

void	ft_sort_spr(t_map *map)
{
	int			i;
	int			y;
	int			nb;
	int			tmp;
	double		tmp2;

	i = 0;
	nb = map->spr_i;
	while (nb > 1)
	{
		nb = (nb * 10) / 13;
		if (nb == 9 || nb == 10)
			nb = 11;
		if (nb < 1)
			nb = 1;
		while (i < map->spr_i - nb)
		{
			y = i + nb;
			if (map->dist[i] < map->dist[y])
			{
				tmp2 = map->dist[y];
				map->dist[y] = map->dist[i];
				map->dist[i] = tmp2;
				tmp = map->order[y];
				map->order[y] = map->order[i];
				map->order[i] = tmp;
			}
			i++;
		}
	}
}

void	ft_calc_dist_spr(t_map *map)
{
	int			i;

	i = 0;
	while (i < map->spr_i)
	{
		map->order[i] = i;
		map->dist[i] = ((PLAYER.pos.x - map->spr[i].pos.x) *
			(PLAYER.pos.x - map->spr[i].pos.x) +
				(PLAYER.pos.y - map->spr[i].pos.y)
					* (PLAYER.pos.y - map->spr[i].pos.y));
		i++;
	}
	ft_sort_spr(map);
}
