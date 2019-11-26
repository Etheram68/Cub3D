/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:29:11 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 16:30:26 by frfrey      ###    #+. /#+    ###.fr     */
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
	mlx_loop_hook(map.id.mlx, ft_raycasting, &map);
	mlx_key_hook(map.id.windows, deal_key, &map);
	/*while (1)
		;*/
	return (0);
}
