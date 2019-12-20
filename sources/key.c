/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:04:14 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 17:47:48 by frfrey      ###    #+. /#+    ###.fr     */
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
	if (key == KEY_SHIFT_LEFT)
		PLAYER.speed_move = 0.10;
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
	if (key == KEY_SHIFT_LEFT)
		PLAYER.speed_move = 0.05;
	return (0);
}

int		deal_key(t_map *map)
{
	if (PLAYER.w == 1)
		ft_move_up_down(map);
	if (PLAYER.s == 1)
		ft_move_up_down(map);
	if (PLAYER.a == 1)
		ft_move_left_rigth(map);
	if (PLAYER.d == 1)
		ft_move_left_rigth(map);
	if (PLAYER.rightarrow == 1)
		ft_move_cam_rigth(map);
	if (PLAYER.leftarrow == 1)
		ft_move_cam_left(map);
	mlx_clear_window(map->id.mlx, map->id.windows);
	ft_raycasting(map);
	mlx_put_image_to_window(map->id.mlx, map->id.windows, map->id.image, 0, 0);
	return (1);
}
