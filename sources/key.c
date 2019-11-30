/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:04:14 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 11:54:46 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		deal_key(int key, t_map *map)
{
	if (key == 53)
		try(map);
	if (key == 13)
		map->player.pos.x -= 0.1;
	if (key == 1)
		map->player.pos.x += 0.1;
	if (key == 0)
		map->player.pos.y -= 0.1;
	if (key == 2)
		map->player.pos.y += 0.1;
	return (1);
}
