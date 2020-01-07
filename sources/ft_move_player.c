/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move_player.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:25:34 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:42:05 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_move_up_down(t_map *map)
{
	if (map->player.w == 1)
	{
		if (map->map[(int)(map->player.pos.y + map->player.dir.y *
			(map->player.speed_move + 0.1))][(int)map->player.pos.x] != 1)
			map->player.pos.y += map->player.dir.y * map->player.speed_move;
		if (map->map[(int)map->player.pos.y][(int)(map->player.pos.x +
			map->player.dir.x * (map->player.speed_move + 0.1))] != 1)
			map->player.pos.x += map->player.dir.x * map->player.speed_move;
	}
	if (map->player.s == 1)
	{
		if (map->map[(int)(map->player.pos.y - map->player.dir.y *
			(map->player.speed_move + 0.1))][(int)map->player.pos.x] != 1)
			map->player.pos.y -= map->player.dir.y * map->player.speed_move;
		if (map->map[(int)map->player.pos.y][(int)(map->player.pos.x -
			map->player.dir.x * (map->player.speed_move + 0.1))] != 1)
			map->player.pos.x -= map->player.dir.x * map->player.speed_move;
	}
}

void	ft_move_left_rigth(t_map *map)
{
	if (map->player.a == 1)
	{
		if (map->map[(int)(map->player.pos.y - map->player.dir.x *
			(map->player.speed_move + 0.1))][(int)map->player.pos.x] != 1)
			map->player.pos.y -= map->player.dir.x * map->player.speed_move;
		if (map->map[(int)map->player.pos.y][(int)(map->player.pos.x +
			map->player.dir.y * (map->player.speed_move + 0.1))] != 1)
			map->player.pos.x += map->player.dir.y * map->player.speed_move;
	}
	if (map->player.d == 1)
	{
		if (map->map[(int)(map->player.pos.y + map->player.dir.x *
			(map->player.speed_move + 0.1))][(int)map->player.pos.x] != 1)
			map->player.pos.y += map->player.dir.x * map->player.speed_move;
		if (map->map[(int)map->player.pos.y][(int)(map->player.pos.x -
			map->player.dir.y * (map->player.speed_move + 0.1))] != 1)
			map->player.pos.x -= map->player.dir.y * map->player.speed_move;
	}
}

void	ft_move_cam_rigth(t_map *map)
{
	double	olddiry;
	double	oldplaney;

	if (map->player.rightarrow == 1)
	{
		olddiry = map->player.dir.y;
		map->player.dir.y = map->player.dir.y * cos(-map->player.speed_rot)
			- map->player.dir.x * sin(-map->player.speed_rot);
		map->player.dir.x = olddiry * sin(-map->player.speed_rot)
			+ map->player.dir.x * cos(-map->player.speed_rot);
		oldplaney = map->player.plane.y;
		map->player.plane.y = map->player.plane.y * cos(-map->player.speed_rot)
			- map->player.plane.x * sin(-map->player.speed_rot);
		map->player.plane.x = oldplaney * sin(-map->player.speed_rot)
			+ map->player.plane.x * cos(-map->player.speed_rot);
	}
}

void	ft_move_cam_left(t_map *map)
{
	double	olddiry;
	double	oldplaney;

	if (map->player.leftarrow == 1)
	{
		olddiry = map->player.dir.y;
		map->player.dir.y = map->player.dir.y * cos(map->player.speed_rot)
			- map->player.dir.x * sin(map->player.speed_rot);
		map->player.dir.x = olddiry * sin(map->player.speed_rot)
			+ map->player.dir.x * cos(map->player.speed_rot);
		oldplaney = map->player.plane.y;
		map->player.plane.y = map->player.plane.y * cos(map->player.speed_rot)
			- map->player.plane.x * sin(map->player.speed_rot);
		map->player.plane.x = oldplaney * sin(map->player.speed_rot)
			+ map->player.plane.x * cos(map->player.speed_rot);
	}
}
