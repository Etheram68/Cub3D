/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_struct.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 12:12:15 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 12:15:08 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

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
	map->color_top = 0;
	map->color_foot = 0;
}
