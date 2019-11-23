/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:08:39 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 18:36:47 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_count_heigth_map(char *line, int *size_map)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] && (map_is_valide(line[i])))
			*size_map = *size_map + 1;
		if (!map_is_valide(line[i]))
			break ;
		i++;
	}
}

void	ft_count_len_map(char *line, int *len_map, t_map *map)
{
	int		i;

	i = 0;
	if (line[0] == '\0')
		return ;
	while (line[i])
	{
		if (line[i] && (map_is_valide(line[i]) || map_player_start(line[i])))
			*len_map = *len_map + 1;
		i++;
	}
	if (map->map_heigth != 0 && map->map_width != 0
		&& map->map_width == *len_map)
		return ;
	else if (map->map_width != 0 && map->map_width != *len_map)
		print_error("error: map does not valid");
	if (map->map_heigth != 0)
		map->map_width = *len_map;
}

int		ft_count_size_map(int fd, t_map *map)
{
	int		ret;
	char	*line;
	int		size_map;
	int		len_map;

	ret = 0;
	size_map = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1 && line == NULL)
			return (print_error("error: Error when you read map"));
		len_map = 0;
		ft_count_heigth_map(line, &size_map);
		ft_count_len_map(line, &len_map, map);
		if (size_map != 0)
			map->map_heigth = size_map;
		free(line);
	}
	if (map->map_heigth == 0 && map->map_width == 0)
		print_error("error: map does not valid");
	close(fd);
	return (0);
}

int		ft_open_map(char **av)
{
	int		fd;
	t_map	map;

	fd = 0;
	ft_init_struct(&map);
	if (!(fd = open(av[1], O_RDONLY)))
		return (print_error("error: map file doesn't not exist"));
	ft_count_size_map(fd, &map);
	if (!(fd = open(av[1], O_RDONLY)))
		return (print_error("error: map file doesn't not exist"));
	ft_parse_map(fd, &map);
	return (1);
}
