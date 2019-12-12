/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 13:12:23 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 18:59:00 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	draw(t_map *map, int x)
{
	int		range_start;
	int		range_end;

	RAY.len = (int)(map->w_height / RAY.dist);
	range_start = -RAY.len / 2 + map->w_height / 2;
	if (range_start < 0)
		range_start = 0;
	range_end = RAY.len / 2 + map->w_height / 2;
	if (range_end >= map->w_height)
		range_end = map->w_height - 1;
	draw_line(map, x, range_start, range_end);
}

void	rayon_dist(t_map *map)
{
	while (RAY.hit == 0)
	{
		if (RAY.side.y < RAY.side.x)
		{
			RAY.side.y += RAY.delta.y;
			RAY.map.y += RAY.step.y;
			RAY.hit_side = 0;
		}
		else
		{
			RAY.side.x += RAY.delta.x;
			RAY.map.x += RAY.step.x;
			RAY.hit_side = 1;
		}
		if (map->map[RAY.map.y][RAY.map.x] == 1)
		{
			RAY.hit = 1;
			if (RAY.hit_side == 0)
				RAY.dist = (RAY.map.y - RAY.pos.y + (1 - RAY.step.y)
								/ 2) / RAY.dir.y;
			else
				RAY.dist = (RAY.map.x - RAY.pos.x + (1 - RAY.step.x)
								/ 2) / RAY.dir.x;
		}
	}
}

void	rayon_side(t_map *map)
{
	if (RAY.dir.y < 0)
	{
		RAY.step.y = -1;
		RAY.side.y = (RAY.pos.y - (int)RAY.pos.y) * RAY.delta.y;
	}
	else
	{
		RAY.step.y = 1;
		RAY.side.y = ((int)RAY.pos.y + 1 - RAY.pos.y) * RAY.delta.y;
	}
	if (RAY.dir.x < 0)
	{
		RAY.step.x = -1;
		RAY.side.x = (RAY.pos.x - (int)RAY.pos.x) * RAY.delta.x;
	}
	else
	{
		RAY.step.x = 1;
		RAY.side.x = ((int)RAY.pos.x + 1 - RAY.pos.x) * RAY.delta.x;
	}
}

/*
**	Initialisation des informations du rayon
**	Ray.dir correspond a la direction ou vas le rayon
**	PLAYER.plane correspond au plan de la camera du joueur (FOV)
**	RAY.delta correspond a la distance que dois parcourir entre chaque coté
*/

void	init_rayon(t_map *map, int x)
{
	RAY.map.y = (int)RAY.pos.y;
	RAY.map.x = (int)RAY.pos.x;
	RAY.cam = 2 * x / (double)map->w_width - 1;
	RAY.dir.x = PLAYER.dir.x + PLAYER.plane.x * RAY.cam;
	RAY.dir.y = PLAYER.dir.y + PLAYER.plane.y * RAY.cam;
	RAY.delta.x = fabs(1 / RAY.dir.x);
	RAY.delta.y = fabs(1 / RAY.dir.y);
	RAY.hit = 0;
	RAY.dist = -1;
	RAY.hit_side = -1;
}

/*
**	@RAY.pos.x initialisation de la position du rayon x ou ce trouve le joueurs.
**	@Ray.pos.Y initialisation de la position du rayon y ou ce trouve la joueurs.
**	Envoie a la fonction Init Rayon, Rayon side, rayon dist.
**	La boucle X parcoure chaque bande verticale
*/

int		ft_raycasting(t_map *map)
{
	int				x;

	x = -1;
	RAY.pos.x = PLAYER.pos.x;
	RAY.pos.y = PLAYER.pos.y;
	while (++x < map->w_width)
	{
		init_rayon(map, x);
		rayon_side(map);
		rayon_dist(map);
		draw(map, x);
	}
	return (1);
}
