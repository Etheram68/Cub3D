/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:04:14 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 15:52:40 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

/*void	ft_move(t_map *map, int bool)
{

}*/

int		deal_key(int key, t_map *map)
{
	if (key == 53)
		try(map);
	if (key == 13)
		PLAYER.pos.x += RAY.dir.x * 0.5;
	if (key == 1)
		PLAYER.pos.x -= RAY.dir.x * 0.5;
	if (key == 0)
		PLAYER.pos.y -= RAY.dir.y * 0.5;
	if (key == 2)
		PLAYER.pos.y += RAY.dir.y * 0.5;
	if (key == 123)
		PLAYER.dir.x += RAY.dir.x;
	if (key == 124)
		PLAYER.dir.y -= RAY.dir.x;
	return (1);
}
