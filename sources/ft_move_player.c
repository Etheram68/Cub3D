/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:25:34 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 13:33:33 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_move_up_down(t_map *map)
{
	if (PLAYER.w == 1)
	{
		if (!(map->map[(int)(PLAYER.pos.x + PLAYER.pos.x * PLAYER.speed_move)]
						[(int)PLAYER.pos.y] == 1))
			PLAYER.pos.x += PLAYER.dir.x * PLAYER.speed_move;
		if (!(map->map[(int)PLAYER.pos.x]
			[(int)(PLAYER.pos.y + PLAYER.dir.y * PLAYER.speed_move)] == 1))
			PLAYER.pos.y += PLAYER.dir.y * PLAYER.speed_move;
	}
	if (PLAYER.s == 1)
	{
		if (!(map->map[(int)(PLAYER.pos.x + PLAYER.dir.x * PLAYER.speed_move)]
			[(int)PLAYER.pos.y] == 1))
			PLAYER.pos.x -= PLAYER.dir.x * PLAYER.speed_move;
		if (!(map->map[(int)PLAYER.pos.x]
			[(int)(PLAYER.pos.y + PLAYER.dir.y * PLAYER.speed_move)] == 1))
			PLAYER.pos.y -= PLAYER.dir.y * PLAYER.speed_move;
	}
}

void	ft_move_left_rigth(t_map *map)
{
	if (PLAYER.a == 1)
	{
		if (!(map->map[(int)(PLAYER.pos.x + PLAYER.dir.y * PLAYER.speed_move)]
			[(int)PLAYER.pos.y] == 1))
			PLAYER.pos.x -= PLAYER.dir.y * PLAYER.speed_move;
		if (!(map->map[(int)PLAYER.pos.x]
			[(int)(PLAYER.pos.y + PLAYER.dir.x * PLAYER.speed_move)] == 1))
			PLAYER.pos.y += PLAYER.dir.x * PLAYER.speed_move;
	}
	if (PLAYER.d == 1)
	{
		if (!(map->map[(int)(PLAYER.pos.x + PLAYER.dir.y * PLAYER.speed_move)]
			[(int)PLAYER.pos.y] == 1))
			PLAYER.pos.x += PLAYER.dir.y * PLAYER.speed_move;
		if (!(map->map[(int)PLAYER.pos.x]
			[(int)(PLAYER.pos.y + PLAYER.dir.x * PLAYER.speed_move)] == 1))
			PLAYER.pos.y -= PLAYER.dir.x * PLAYER.speed_move;
	}
}

void	ft_move_cam_rigth(t_map *map)
{
	double	olddirx;
	double	oldplanex;

	if (PLAYER.rightarrow == 1)
	{
		olddirx = PLAYER.dir.x;
		PLAYER.dir.x = PLAYER.dir.x * cos(-PLAYER.speed_rot)
			- PLAYER.dir.y * sin(-PLAYER.speed_rot);
		PLAYER.dir.y = olddirx * sin(-PLAYER.speed_rot)
			+ PLAYER.dir.y * cos(-PLAYER.speed_rot);
		oldplanex = PLAYER.plane.x;
		PLAYER.plane.x = PLAYER.plane.x * cos(-PLAYER.speed_rot)
			- PLAYER.plane.y * sin(-PLAYER.speed_rot);
		PLAYER.plane.y = oldplanex * sin(-PLAYER.speed_rot)
			+ PLAYER.plane.y * cos(-PLAYER.speed_rot);
	}
}

void	ft_move_cam_left(t_map *map)
{
	double	olddirx;
	double	oldplanex;

	if (PLAYER.leftarrow == 1)
	{
		olddirx = PLAYER.dir.x;
		PLAYER.dir.x = PLAYER.dir.x * cos(PLAYER.speed_rot)
			- PLAYER.dir.y * sin(PLAYER.speed_rot);
		PLAYER.dir.y = olddirx * sin(PLAYER.speed_rot)
			+ PLAYER.dir.y * cos(PLAYER.speed_rot);
		oldplanex = PLAYER.plane.x;
		PLAYER.plane.x = PLAYER.plane.x * cos(PLAYER.speed_rot)
			- PLAYER.plane.y * sin(PLAYER.speed_rot);
		PLAYER.plane.y = oldplanex * sin(PLAYER.speed_rot)
			+ PLAYER.plane.y * cos(PLAYER.speed_rot);
	}
}
