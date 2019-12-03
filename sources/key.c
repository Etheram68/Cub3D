/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:04:14 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 19:18:05 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		ft_holdinput(int key, t_map *map)
{
	if (key == KEY_LEFT)
		map->player.leftarrow = 1;
	else if (key == KEY_RIGHT)
		map->player.rightarrow = 1;
	if (key == KEY_W)
		map->player.w = 1;
	if (key == KEY_A)
		map->player.a = 1;
	if (key == KEY_S)
		map->player.s = 1;
	if (key == KEY_D)
		map->player.d = 1;
	if (key == KEY_ESCAPE)
		try(map);
	return (0);
}

int		ft_releaseinput(int key, t_map *map)
{
	if (key == KEY_LEFT)
		map->player.leftarrow = 0;
	else if (key == KEY_RIGHT)
		map->player.rightarrow = 0;
	if (key == KEY_W)
		map->player.w = 0;
	if (key == KEY_A)
		map->player.a = 0;
	if (key == KEY_S)
		map->player.s = 0;
	if (key == KEY_D)
		map->player.d = 0;
	return (0);
}

int		deal_key(t_map *map)
{
	double	olddirx;
	double	oldplanex;

	if (map->player.w == 1)
	{
		if (map->map[(int)(PLAYER.pos.x + PLAYER.dir.x * 0.5)][(int)PLAYER.pos.y] == 0)
			PLAYER.pos.x += PLAYER.dir.x * 0.5;
		if (map->map[(int)PLAYER.pos.x][(int)(PLAYER.pos.y + PLAYER.dir.y * 0.5)] == 0)
			PLAYER.pos.y += PLAYER.dir.y * 0.5;
	}
	if (map->player.s == 1)
	{
		if (map->map[(int)(PLAYER.pos.x + PLAYER.dir.x * 0.5)][(int)PLAYER.pos.y] == 0)
			PLAYER.pos.x -= PLAYER.dir.y * 0.5;
		if (map->map[(int)PLAYER.pos.x][(int)(PLAYER.pos.y + PLAYER.dir.y * 0.5)] == 0)
			PLAYER.pos.y -= PLAYER.dir.y * 0.5;
	}
	if (map->player.a == 1)
	{
		if (map->map[(int)(PLAYER.pos.x + PLAYER.dir.y * 0.5)][(int)PLAYER.pos.y] == 0)
			PLAYER.pos.x -= PLAYER.dir.y * 0.5;
		if (map->map[(int)PLAYER.pos.x][(int)(PLAYER.pos.y + PLAYER.dir.x * 0.5)] == 0)
			PLAYER.pos.y += PLAYER.dir.x * 0.5;
	}
	if (map->player.d == 1)
	{
		if (map->map[(int)(PLAYER.pos.x + PLAYER.dir.y * 0.5)][(int)PLAYER.pos.y] == 0)
			PLAYER.pos.x += PLAYER.dir.y * 0.5;
		if (map->map[(int)PLAYER.pos.x][(int)(PLAYER.pos.y + PLAYER.dir.x * 0.5)] == 0)
			PLAYER.pos.y -= PLAYER.dir.x * 0.5;
	}
	if (map->player.rightarrow == 1)
	{
		olddirx = PLAYER.dir.x;
		PLAYER.dir.x = PLAYER.dir.x * cos(-0.05) - PLAYER.dir.y * sin(-0.05);
		PLAYER.dir.y = olddirx * sin(-0.05) + PLAYER.dir.y * cos(-0.05);
		oldplanex = PLAYER.plane.x;
		PLAYER.plane.x = PLAYER.plane.x * cos(-0.05) - PLAYER.plane.y * sin(-0.05);
		PLAYER.plane.y = oldplanex * sin(-0.05) + PLAYER.plane.y * cos(-0.05);
	}
	if (map->player.leftarrow == 1)
	{
		olddirx = PLAYER.dir.x;
		PLAYER.dir.x = PLAYER.dir.x * cos(0.05) - PLAYER.dir.y * sin(0.05);
		PLAYER.dir.y = olddirx * sin(0.05) + PLAYER.dir.y * cos(0.05);
		oldplanex = PLAYER.plane.x;
		PLAYER.plane.x = PLAYER.plane.x * cos(0.05) - PLAYER.plane.y * sin(0.05);
		PLAYER.plane.y = oldplanex * sin(0.05) + PLAYER.plane.y * cos(0.05);
	}
	ft_raycasting(map);
	mlx_put_image_to_window(map->id.mlx, map->id.windows, map->id.image, 0, 0);
	return (1);
}
