/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 15:02:56 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 12:41:10 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void		dist_wall(t_map *map)
{
	RAY.hit = 1;
	if (RAY.hit_side == 0)
		RAY.dist = (RAY.map.y - RAY.pos.y + (1 - RAY.step.y)
						/ 2) / RAY.dir.y;
	else
		RAY.dist = (RAY.map.x - RAY.pos.x + (1 - RAY.step.x)
						/ 2) / RAY.dir.x;
}

void		dist_sprite(t_map *map, t_sprite *spr)
{
	RAY.sprite = 1;
	spr[map->spr_i].pos.x = RAY.map.x;
	spr[map->spr_i].pos.y = RAY.map.y;
	spr[map->spr_i].type = map->map[RAY.map.y][RAY.map.x];
	spr[map->spr_i].dist = ((PLAYER.pos.y - spr[map->spr_i].pos.y)
					* (PLAYER.pos.y - spr[map->spr_i].pos.y) +
						(PLAYER.pos.x - spr[map->spr_i].pos.x)
							* (PLAYER.pos.x - spr[map->spr_i].pos.x));
	map->spr_i += 1;
}
