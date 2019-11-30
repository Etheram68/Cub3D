/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 17:11:42 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 11:43:09 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	draw_pixel(t_map *map, int x, int y, unsigned int c)
{
	map->id.data[y * map->w_width + x] = c;
}

void	draw_line(t_map *map, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	i = -1;
	c = 0xff9600;
	while (++i < start)
	{
		draw_pixel(map, x, i, ft_atoi_base(map->color_ceil, 16));
	}
	i--;
	while (++i <= end && i < map->w_height)
	{
		draw_pixel(map, x, i, c);
	}
	i--;
	while (++i < map->w_height)
		draw_pixel(map, x, i, ft_atoi_base(map->color_floor, 16));
}
