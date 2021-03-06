/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:29:11 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:38:26 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_free_struct(t_map *map)
{
	int		i;

	i = 0;
	free(map->color_ceil);
	free(map->color_floor);
	if (map->map != NULL)
	{
		while (i < map->map_heigth)
			free(map->map[i++]);
		free(map->map);
	}
	if (map->t_north != NULL)
		free(map->t_north);
	if (map->t_south != NULL)
		free(map->t_south);
	if (map->t_west != NULL)
		free(map->t_west);
	if (map->t_east != NULL)
		free(map->t_east);
	if (map->sprite != NULL)
		free(map->sprite);
}

int		try(t_map *map)
{
	if (map->save == 0)
	{
		mlx_clear_window(map->id.mlx, map->id.windows);
		if (!(mlx_destroy_window(map->id.mlx, map->id.windows)))
		{
			ft_free_struct(map);
			exit(EXIT_SUCCESS);
		}
		else
		{
			ft_free_struct(map);
			print_error("Error:\nWhen you destroy thw windows\n", map);
			exit(EXIT_FAILURE);
		}
	}
	ft_free_struct(map);
	exit(EXIT_SUCCESS);
	return (1);
}

void	ft_init_mlx(t_map *map)
{
	if (!(map->id.mlx = mlx_init()))
		print_error("Error:\nWhen you init id mlx\n", map);
	if (map->save == 0)
		if (!(map->id.windows = mlx_new_window(map->id.mlx,
				map->w_width, map->w_height, "Cube3D")))
			print_error("Eroor:\nWhen you initialise windows\n", map);
	map->id.image = mlx_new_image(map->id.mlx, map->w_width, map->w_height);
	map->id.data = (int *)mlx_get_data_addr(map->id.image,
							&map->id.bits, &map->id.line, &map->id.endian);
	ft_init_texture(map);
	ft_init_dir_player(map);
}

int		ft_check_argv(int ac, char **av, t_map *map)
{
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7) != 0)
			return (print_error("Error:\nInvalid argument\n", map));
		else
			map->save = 1;
	}
	ft_open_map(av, map);
	return (1);
}

int		main(int ac, char **av)
{
	t_map	map;

	ft_init_struct(&map);
	if (ac > 1)
		ft_check_argv(ac, av, &map);
	else
		return (print_error("Error:\nInvalid map file\n", &map));
	ft_init_mlx(&map);
	if (map.save == 1)
	{
		ft_raycasting(&map);
		save_bitmap("cube.bmp", &map);
		try(&map);
	}
	mlx_loop_hook(map.id.mlx, deal_key, &map);
	mlx_hook(map.id.windows, 2, 0, ft_holdinput, &map);
	mlx_hook(map.id.windows, 3, 0, ft_releaseinput, &map);
	mlx_hook(map.id.windows, 17, 0, try, &map);
	mlx_loop(map.id.mlx);
	return (0);
}
