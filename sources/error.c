/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:13:24 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 17:18:07 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_check_texture(char *line, t_map *map)
{
	if (line[0] == 'N')
	{
		if (map->t_north == NULL)
			print_error("Error:\nInvalid texture north\n");
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (map->t_south == NULL)
			print_error("Error:\nInvalid texture south\n");
	}
	else if (line[0] == 'W')
	{
		if (map->t_west == NULL)
			print_error("Error:\nInvalid texture west\n");
	}
	else if (line[0] == 'S' && line[1] != 'O')
	{
		if (map->sprite == NULL)
			print_error("Error:\nInvalid texture for sprite\n");
	}
	else if (line[0] == 'E')
		if (map->t_east == NULL)
			print_error("Error:\nInvalid texture east\n");
}

void	ft_check_multi_player_start(t_map *map)
{
	if (map->player.pos.x != 0 && map->player.pos.y != 0)
		print_error("Error:\nInvalid map you are twince player start\n");
}

void	ft_check_player_start(t_map *map)
{
	if (map->player.pos.x == 0 && map->player.pos.y == 0)
		print_error("Error:\nInvalid map you are not player start\n");
}

int		print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
	return (1);
}
