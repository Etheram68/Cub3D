/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:08:39 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 14:58:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_count_heigth_map(char *line, int *size_map)
{
	int		i;

	i = 0;
	if (line[0] == '\0')
		return ;
	if (line[i] && (map_is_valide(line[i])))
		*size_map = *size_map + 1;
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
		print_error("Error:\nMap does not valid\n", map);
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
			return (print_error("Error:\nError when you read map\n", map));
		len_map = 0;
		ft_count_heigth_map(line, &size_map);
		ft_count_len_map(line, &len_map, map);
		if (size_map != 0)
			map->map_heigth = size_map;
		free(line);
	}
	if (map->map_heigth == 0 && map->map_width == 0)
		print_error("Error:\nMap does not valid\n", map);
	free(line);
	close(fd);
	return (0);
}

void	ft_check_arg(char *name, t_map *map)
{
	int i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (name[i] == '.')
	{
		if (ft_strncmp(name + i, ".cub", 5) != 0)
			print_error_nf("Error:\nMap has not extension cub\n", map);
	}
	else
		print_error_nf("Error:\nMap has not extension cub\n", map);
}

int		ft_open_map(char **av, t_map *map)
{
	int		fd;

	fd = 0;
	ft_check_arg(av[1], map);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (print_error_nf("Error:\nMap file doesn't not exist\n", map));
	ft_count_size_map(fd, map);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (print_error_nf("Error:\nMap file doesn't not exist\n", map));
	ft_parse_map(fd, map);
	return (1);
}
