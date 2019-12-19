/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bitmap.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 16:19:13 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 19:42:02 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	bitmap_image(t_map *map, int fd, t_bih bih)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bih, sizeof(bih));
	y = map->w_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < map->w_width)
		{
			ble = map->id.data[x + (y * map->w_width)];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void	save_bitmap(char *filename, t_map *map)
{
	int			fd;
	t_bfh		bfh;
	t_bih		bih;

	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size = (map->w_width * map->w_height) * 4 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset_bits = 0;
	bih.size_header = sizeof(bih);
	bih.width = map->w_width;
	bih.height = map->w_height;
	bih.planes = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	bih.image_size = map->w_width * map->w_height * 4 + 54;
	bih.ppm_x = 2;
	bih.ppm_y = 2;
	bih.clr_used = 0;
	bih.clr_important = 0;
	fd = open(filename, O_WRONLY | O_CREAT, 0777);
	write(fd, &bfh, 14);
	bitmap_image(map, fd, bih);
	close(fd);
}
