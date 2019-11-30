/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:13:24 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 10:43:32 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		ft_is_border(char c, t_map *map)
{
	if (c == 1)
		return (TRUE);
	print_error("Error:\nThe border is not a wall\n", map);
	return (FALSE);
}

void	ft_check_texture(char *line, t_map *map)
{
	if (line[0] == 'N')
	{
		if (map->t_north == NULL)
			print_error("Error:\nInvalid texture north\n", map);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (map->t_south == NULL)
			print_error("Error:\nInvalid texture south\n", map);
	}
	else if (line[0] == 'W')
	{
		if (map->t_west == NULL)
			print_error("Error:\nInvalid texture west\n", map);
	}
	else if (line[0] == 'S' && line[1] != 'O')
	{
		if (map->sprite == NULL)
			print_error("Error:\nInvalid texture for sprite\n", map);
	}
	else if (line[0] == 'E')
		if (map->t_east == NULL)
			print_error("Error:\nInvalid texture east\n", map);
}

void	ft_check_multi_player_start(t_map *map)
{
	if (map->player.pos.x != 0 && map->player.pos.y != 0)
		print_error("Error:\nInvalid map you are twince player start\n", map);
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
	return (1);
}
