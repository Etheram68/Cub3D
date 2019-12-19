/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_struct.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 12:12:15 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 17:42:41 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_init_dir_player_ew(t_map *map)
{
	if (map->dir == 'W')
	{
		map->player.dir.y = 0;
		map->player.dir.x = -1;
		map->player.plane.y = -0.66;
		map->player.plane.x = 0;
	}
	if (map->dir == 'E')
	{
		map->player.dir.y = 0;
		map->player.dir.x = 1;
		map->player.plane.y = 0.66;
		map->player.plane.x = 0;
	}
}

void	ft_init_dir_player(t_map *map)
{
	if (map->dir == 'N')
	{
		map->player.dir.y = -1;
		map->player.dir.x = 0;
		map->player.plane.y = 0;
		map->player.plane.x = 0.66;
	}
	if (map->dir == 'S')
	{
		map->player.dir.y = 1;
		map->player.dir.x = 0;
		map->player.plane.y = 0;
		map->player.plane.x = -0.66;
	}
	ft_init_dir_player_ew(map);
}

void	ft_init_player(t_map *map)
{
	map->player.pos.y = 0;
	map->player.pos.x = 0;
	map->player.speed_move = 0.03;
	map->player.speed_rot = 0.03;
}

void	ft_init_id(t_map *map)
{
	map->id.bits = 0;
	map->id.line = 0;
	map->id.endian = 0;
}

void	ft_init_struct(t_map *map)
{
	map->map = NULL;
	map->map_heigth = 0;
	map->map_width = 0;
	map->w_height = 0;
	map->w_width = 0;
	map->t_north = NULL;
	map->t_south = NULL;
	map->t_west = NULL;
	map->t_east = NULL;
	map->sprite = NULL;
	map->color_ceil = ft_strdup("");
	map->color_floor = ft_strdup("");
	map->rgb.r = 0;
	map->rgb.g = 0;
	map->rgb.b = 0;
	map->spr_i = 0;
	ft_init_player(map);
	ft_init_id(map);
	ft_init_tex(map);
}
