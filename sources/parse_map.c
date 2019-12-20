/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_map.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 12:48:43 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 12:16:44 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_texture(char *line, t_map *map)
{
	int		i;

	i = 0;
	while (line[i] && is_texture(line[i]))
		i++;
	if (line[0] == 'N')
		map->t_north = ft_strjoin(map->t_north, &line[i++]);
	else if (line[0] == 'S' && line[1] == 'O')
		map->t_south = ft_strjoin(map->t_south, &line[i++]);
	else if (line[0] == 'W')
		map->t_west = ft_strjoin(map->t_west, &line[i++]);
	else if (line[0] == 'E')
		map->t_east = ft_strjoin(map->t_east, &line[i++]);
	else if (line[0] == 'S')
		map->sprite = ft_strjoin(map->sprite, &line[i++]);
	ft_check_texture(line, map);
}

void	ft_check_type(char *line, t_map *map)
{
	if (line[0] == 'R')
		ft_size_windows(line, map);
	else if (is_texture(line[0]))
		ft_texture(line, map);
	else if (line[0] == 'F')
		ft_take_color(line, map);
	else if (line[0] == 'C')
		ft_take_color(line, map);
	else if (line[0] != '\n' && line[0] != '\0' && map_is_valide(line[0]))
		ft_take_map(line, map);
	else if (line[0] != '\n' && line[0] != 'R' && line[0] != 'F' &&
				line[0] != 'C' && !map_is_valide(line[0]) && line[0] != '\0')
		print_error("Error:\nFille conf is invalid\n", map);
}

void	ft_check_map_is_valide(t_map *map)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < map->map_width)
		ft_is_border(map->map[y][i++], map);
	i--;
	while (y < map->map_heigth)
		ft_is_border(map->map[y++][i], map);
	y = 0;
	i = 0;
	while (y < map->map_heigth)
		ft_is_border(map->map[y++][i], map);
	i = 0;
	y--;
	while (i < map->map_width)
		ft_is_border(map->map[y][i++], map);
}

int		ft_parse_map(int fd, t_map *map)
{
	int		ret;
	char	*line;

	ret = 0;
	if (!(map->map = ft_calloc(sizeof(int **), map->map_heigth)))
		return (print_error("Error:\nAllocation of map failled\n", map));
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1 && line == NULL)
			return (print_error("Error:\nWhen read map for parsing\n", map));
		ft_check_type(line, map);
		free(line);
	}
	free(line);
	close(fd);
	if (map->w_height == 0 || map->w_width == 0)
		print_error("Error:\nParams size of windows does not exist\n", map);
	if (map->color_floor[0] == '\0' || map->color_ceil[0] == '\0')
		print_error("Error:\nParams colors does not exist\n", map);
	ft_check_player_start(map);
	ft_check_map_is_valide(map);
	return (1);
}
