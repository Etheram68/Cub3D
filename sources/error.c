/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:13:24 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 15:21:10 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_check_texture(char *line, t_map *map)
{
	if (line[0] == 'N')
	{
		if (map->t_north == NULL)
			print_error("error: Invalid texture north");
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (map->t_south == NULL)
			print_error("error: Invalid texture south");
	}
	else if (line[0] == 'W')
	{
		if (map->t_west == NULL)
			print_error("error: Invalid texture west");
	}
	else if (line[0] == 'S' && line[1] != 'O')
	{
		if (map->sprite == NULL)
			print_error("error: Invalid texture for sprite");
	}
	else if (line[0] == 'E')
		if (map->t_east == NULL)
			print_error("error: Invalid texture east");
}

int		print_error(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
	return (1);
}
