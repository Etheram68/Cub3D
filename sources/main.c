/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:29:11 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 17:39:35 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		try(t_map *map)
{
	mlx_clear_window(map->id.mlx, map->id.windows);
	if (!(mlx_destroy_window(map->id.mlx, map->id.windows)))
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return (1);
}

int		changecolor(t_map *map)
{
	int x = 0;
	int y = 0;
	int *data;
	int bits = 0;
	int size = 0;
	int endian = 0;

	//map->id.color = map->id.color - 10000;
	data = (int *)mlx_get_data_addr(map->id.image, &bits, &size, &endian);
	while (y < 1920)
	{
		x = 0;
		while (x < 1080)
		{
			data[y * 1080 + x] = map->id.color + x;
			x++;
		}
		y++;
		map->id.color = map->id.color + 1;
	}
	mlx_put_image_to_window(map->id.mlx, map->id.windows, map->id.image, 0, 0);
	return (1);
}

int		main(int ac, char **av)
{
	t_map	map;

	ft_init_struct(&map);
	if (ac == 2)
		ft_open_map(av, &map);
	else
		return (print_error("Error:\nInvalid map file\n"));
	if (!(map.id.mlx = mlx_init()))
		print_error("Error:\nWhen you init id mlx\n");
	if (!(map.id.windows = mlx_new_window(map.id.mlx,
			map.w_width, map.w_height, "Cube3D")))
		print_error("Eroor:\nWhen you initialise windows\n");
	map.id.image = mlx_new_image(map.id.mlx, map.w_width, map.w_height);
	mlx_loop_hook(map.id.mlx, ft_raycasting, &map);
	mlx_key_hook(map.id.windows, deal_key, &map);
	mlx_hook(map.id.windows, 17, 0, try, &map);
	mlx_loop(map.id.mlx);
	return (0);
}
