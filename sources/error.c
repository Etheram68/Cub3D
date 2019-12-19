/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:13:24 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 14:30:29 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_check_texture(char *line, t_map *map)
{
	if (line[0] == 'N')
	{
		if (ft_check_tex(map->t_north))
			print_error("Error:\nInvalid texture north\n", map);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (ft_check_tex(map->t_south))
			print_error("Error:\nInvalid texture south\n", map);
	}
	else if (line[0] == 'W')
	{
		if (ft_check_tex(map->t_west))
			print_error("Error:\nInvalid texture west\n", map);
	}
	else if (line[0] == 'S' && line[1] != 'O')
	{
		if (ft_check_tex(map->sprite))
			print_error("Error:\nInvalid texture for sprite\n", map);
	}
	else if (line[0] == 'E')
		if (ft_check_tex(map->t_east))
			print_error("Error:\nInvalid texture east\n", map);
}

void	ft_check_multi_player_start(t_map *map, char dir)
{
	if (map->player.pos.x != 0 && map->player.pos.y != 0)
		print_error("Error:\nInvalid map you are twince player start\n", map);
	map->dir = dir;
}

void	ft_check_player_start(t_map *map)
{
	if (map->player.pos.x == 0 && map->player.pos.y == 0)
		print_error("Error:\nInvalid map you are not player start\n", map);
}

int		print_error(char *str, t_map *map)
{
	ft_putstr_fd(str, 2);
	ft_free_struct(map);
	exit(EXIT_FAILURE);
	return (0);
}

int		print_error_nf(char *str, t_map *map)
{
	ft_putstr_fd(str, 2);
	free(map->color_ceil);
	free(map->color_floor);
	exit(EXIT_FAILURE);
	return (0);
}
