/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calc_obj.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 15:02:56 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 17:21:42 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	cal_dist_wall(t_map *map)
{
	RAY.hit = 1;
	if (RAY.hit_side == 0)
		RAY.dist = (RAY.map.y - RAY.pos.y + (1 - RAY.step.y)
						/ 2) / RAY.dir.y;
	else
		RAY.dist = (RAY.map.x - RAY.pos.x + (1 - RAY.step.x)
						/ 2) / RAY.dir.x;
}

void	cal_dist_sprite(t_map *map)
{
	RAY.sprite = 1;
	if (RAY.hit_side == 0)
		RAY.dist = (RAY.map.y - RAY.pos.y + (1 - RAY.step.y)
						/ 2) / RAY.dir.y;
	else
		RAY.dist = (RAY.map.x - RAY.pos.x + (1 - RAY.step.x)
						/ 2) / RAY.dir.x;
}
