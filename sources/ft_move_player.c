/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:25:34 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 17:17:58 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_move_up_down(t_map *map)
{
	if (PLAYER.w == 1)
	{
		if (map->map[(int)(PLAYER.pos.y + PLAYER.dir.y * PLAYER.speed_move)]
						[(int)PLAYER.pos.x] != 1)
			PLAYER.pos.y += PLAYER.dir.y * PLAYER.speed_move;
		if (map->map[(int)PLAYER.pos.y]
			[(int)(PLAYER.pos.x + PLAYER.dir.x * PLAYER.speed_move)] != 1)
			PLAYER.pos.x += PLAYER.dir.x * PLAYER.speed_move;
	}
	if (PLAYER.s == 1)
	{
		if (map->map[(int)(PLAYER.pos.y - PLAYER.dir.y * PLAYER.speed_move)]
			[(int)PLAYER.pos.x] != 1)
			PLAYER.pos.y -= PLAYER.dir.y * PLAYER.speed_move;
		if (map->map[(int)PLAYER.pos.y]
			[(int)(PLAYER.pos.x - PLAYER.dir.x * PLAYER.speed_move)] != 1)
			PLAYER.pos.x -= PLAYER.dir.x * PLAYER.speed_move;
	}
}

void	ft_move_left_rigth(t_map *map)
{
	if (PLAYER.a == 1)
	{
		if (map->map[(int)(PLAYER.pos.y - PLAYER.dir.x * PLAYER.speed_move)]
			[(int)PLAYER.pos.x] != 1)
			PLAYER.pos.y -= PLAYER.dir.x * PLAYER.speed_move;
		if (map->map[(int)PLAYER.pos.y]
			[(int)(PLAYER.pos.x + PLAYER.dir.y * PLAYER.speed_move)] != 1)
			PLAYER.pos.x += PLAYER.dir.y * PLAYER.speed_move;
	}
	if (PLAYER.d == 1)
	{
		if (map->map[(int)(PLAYER.pos.y + PLAYER.dir.x * PLAYER.speed_move)]
			[(int)PLAYER.pos.x] != 1)
			PLAYER.pos.y += PLAYER.dir.x * PLAYER.speed_move;
		if (map->map[(int)PLAYER.pos.y]
			[(int)(PLAYER.pos.x - PLAYER.dir.y * PLAYER.speed_move)] != 1)
			PLAYER.pos.x -= PLAYER.dir.y * PLAYER.speed_move;
	}
}

void	ft_move_cam_rigth(t_map *map)
{
	double	olddiry;
	double	oldplaney;

	if (PLAYER.rightarrow == 1)
	{
		olddiry = PLAYER.dir.y;
		PLAYER.dir.y = PLAYER.dir.y * cos(-PLAYER.speed_rot)
			- PLAYER.dir.x * sin(-PLAYER.speed_rot);
		PLAYER.dir.x = olddiry * sin(-PLAYER.speed_rot)
			+ PLAYER.dir.x * cos(-PLAYER.speed_rot);
		oldplaney = PLAYER.plane.y;
		PLAYER.plane.y = PLAYER.plane.y * cos(-PLAYER.speed_rot)
			- PLAYER.plane.x * sin(-PLAYER.speed_rot);
		PLAYER.plane.x = oldplaney * sin(-PLAYER.speed_rot)
			+ PLAYER.plane.x * cos(-PLAYER.speed_rot);
	}
}

void	ft_move_cam_left(t_map *map)
{
	double	olddiry;
	double	oldplaney;

	if (PLAYER.leftarrow == 1)
	{
		olddiry = PLAYER.dir.y;
		PLAYER.dir.y = PLAYER.dir.y * cos(PLAYER.speed_rot)
			- PLAYER.dir.x * sin(PLAYER.speed_rot);
		PLAYER.dir.x = olddiry * sin(PLAYER.speed_rot)
			+ PLAYER.dir.x * cos(PLAYER.speed_rot);
		oldplaney = PLAYER.plane.y;
		PLAYER.plane.y = PLAYER.plane.y * cos(PLAYER.speed_rot)
			- PLAYER.plane.x * sin(PLAYER.speed_rot);
		PLAYER.plane.x = oldplaney * sin(PLAYER.speed_rot)
			+ PLAYER.plane.x * cos(PLAYER.speed_rot);
	}
}
