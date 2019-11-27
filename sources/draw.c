/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:11:42 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 17:29:48 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	draw_pixel(t_map *map, int x, int i, unsigned int c)
{
	int		y;

	y = (x * 4) + (i * map->id.line);
	map->id.data[y] = c;
}

void	draw_line(t_map *map, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	c = 0x4876ff;
	i = -1;
	while (++i < start)
		draw_pixel(map, x, i, 0xf0ffff);
	i--;
	while (++i <= end && i < map->w_height)
		draw_pixel(map, x, i, c);
	i--;
	while (++i < map->w_height)
		draw_pixel(map, x, i, 0xfff0f5);
}
