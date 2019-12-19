/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_textur.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 13:49:10 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 17:38:06 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		ft_check_tex(char *tex)
{
	int		ret;
	int		fd;

	ret = 0;
	if (tex == NULL)
		return (1);
	fd = open(tex, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}

void	ft_init_tex(t_map *map)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		map->tex[i].bits = 0;
		map->tex[i].line = 0;
		map->tex[i].endian = 0;
		map->tex[i].size = 64;
	}
}

void	ft_init_sprite(t_map *map)
{
	int		size;

	size = 64;
	map->tex[4].image = mlx_xpm_file_to_image(map->id.mlx,
									map->sprite, &size, &size);
	map->tex[4].data = (int *)mlx_get_data_addr(map->tex[4].image,
					&map->tex[4].bits, &map->tex[4].line, &map->tex[4].endian);
}

void	ft_init_texture(t_map *map)
{
	int		size;

	size = 64;
	map->tex[0].image = mlx_xpm_file_to_image(map->id.mlx,
									map->t_north, &size, &size);
	map->tex[0].data = (int *)mlx_get_data_addr(map->tex[0].image,
					&map->tex[0].bits, &map->tex[0].line, &map->tex[0].endian);
	map->tex[1].image = mlx_xpm_file_to_image(map->id.mlx,
									map->t_south, &size, &size);
	map->tex[1].data = (int *)mlx_get_data_addr(map->tex[1].image,
					&map->tex[1].bits, &map->tex[1].line, &map->tex[1].endian);
	map->tex[2].image = mlx_xpm_file_to_image(map->id.mlx,
									map->t_east, &size, &size);
	map->tex[2].data = (int *)mlx_get_data_addr(map->tex[2].image,
					&map->tex[2].bits, &map->tex[2].line, &map->tex[2].endian);
	map->tex[3].image = mlx_xpm_file_to_image(map->id.mlx,
									map->t_west, &size, &size);
	map->tex[3].data = (int *)mlx_get_data_addr(map->tex[3].image,
					&map->tex[3].bits, &map->tex[3].line, &map->tex[3].endian);
	ft_init_sprite(map);
}
