/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_map.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 12:48:43 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 10:06:01 by frfrey      ###    #+. /#+    ###.fr     */
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
	else if (line[0] == 'S' && line[1] != 'O')
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
	else if (line[0] != '\n' && line[0] != '\0')
		ft_take_map(line, map);
}

int		ft_parse_map(int fd, t_map *map)
{
	int		ret;
	char	*line;
	int		i;
	int		y;

	ret = 0;
	i = 0;
	y = 0;
	if (!(map->map = ft_calloc(sizeof(int **), map->map_heigth + 1)))
		return (print_error("Error:\nAllocation of map failled\n"));
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1 && line == NULL)
			return (print_error("Error:\nError when you read map for parsing\n"));
		ft_check_type(line, map);
		free(line);
	}
	map->map[y] = NULL;
	for (int g = 0; map->map[g]; g++)
	{
		ft_printf("%s\n", map->map[g]);
	}
	close(fd);
	return (1);
}
