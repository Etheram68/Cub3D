/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite_casting.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 14:13:34 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:48:28 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	calc_sprite(t_map *map, int i)
{
	map->csp.sprite.x = map->spr[map->order[i]].pos.x - map->player.pos.x;
	map->csp.sprite.y = map->spr[map->order[i]].pos.y - map->player.pos.y;
	map->csp.multi = 1 / (map->player.plane.y * map->player.dir.x -
					map->player.dir.y * map->player.plane.x);
	map->csp.form.x = map->csp.multi * (map->player.dir.x * map->csp.sprite.y -
					map->player.dir.y * map->csp.sprite.x);
	map->csp.form.y = map->csp.multi *
		(-map->player.plane.x * map->csp.sprite.y +
					map->player.plane.y * map->csp.sprite.x);
	map->csp.screen = (int)((map->w_width / 2) *
					(1 + map->csp.form.x / map->csp.form.y));
	map->csp.s_height = abs((int)(map->w_height / (map->csp.form.y)));
	map->csp.start.y = -map->csp.s_height / 2 + map->w_height / 2;
	if (map->csp.start.y < 0)
		map->csp.start.y = 0;
	map->csp.end.y = map->csp.s_height / 2 + map->w_height / 2;
	if (map->csp.end.y >= map->w_height)
		map->csp.end.y = map->w_height - 1;
	map->csp.s_width = abs((int)(map->w_height / (map->csp.form.y)));
	map->csp.start.x = -map->csp.s_width / 2 + map->csp.screen;
	if (map->csp.start.x < 0)
		map->csp.start.x = 0;
	map->csp.end.x = map->csp.s_width / 2 + map->csp.screen;
	if (map->csp.end.x >= map->w_width)
		map->csp.end.x = map->w_width - 1;
}

void	ft_swap_spr(t_map *map, int y, int i)
{
	int			tmp;
	double		tmp2;

	if (map->dist[i] < map->dist[y])
	{
		tmp2 = map->dist[y];
		map->dist[y] = map->dist[i];
		map->dist[i] = tmp2;
		tmp = map->order[y];
		map->order[y] = map->order[i];
		map->order[i] = tmp;
	}
}

void	ft_sort_spr(t_map *map)
{
	int			i;
	int			y;
	int			nb;
	int			invers;

	i = 0;
	nb = map->spr_i;
	invers = 1;
	while (invers && nb > 1)
	{
		invers = 0;
		nb = (nb * 10) / 13;
		while (i < map->spr_i - nb)
		{
			y = i + 1;
			if (map->dist[i] < map->dist[y])
			{
				ft_swap_spr(map, y, i);
				invers = 1;
				i = 0;
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
		map->dist[i] = ((map->player.pos.x - map->spr[i].pos.x) *
			(map->player.pos.x - map->spr[i].pos.x) +
				(map->player.pos.y - map->spr[i].pos.y)
					* (map->player.pos.y - map->spr[i].pos.y));
		i++;
	}
	ft_sort_spr(map);
}
