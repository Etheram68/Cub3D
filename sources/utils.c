/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 17:04:15 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 12:15:23 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_size_windows(char *line, t_map *map)
{
	int		i;

	i = 0;
	if (line[i] == 'R')
	{
		if (map->w_width != 0)
			print_error("Error:\nMulti resolution is forbiden\n", map);
		map->w_width = ft_atoi(&line[++i]);
	}
	i++;
	while (line[i] != '\0' && (line[i] >= '0' && line[i] <= '9'))
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
		map->w_height = ft_atoi(&line[i]);
	if (map->w_height > 1440)
		map->w_height = 1440;
	if (map->w_width > 2560)
		map->w_width = 2560;
	if (map->w_height <= 0 || map->w_width <= 0)
		print_error("Error:\nResolution is invalid\n", map);
	if (map->w_height < 100 || map->w_width < 100)
		ft_resize_winows(map);
}

void	ft_convert_rgb(char *line, t_map *map)
{
	map->r = ft_itoa_base(map->rgb.r, 16);
	if (ft_strlen(map->r) == 1)
		map->r = ft_strjoin_free2("0", map->r);
	map->g = ft_itoa_base(map->rgb.g, 16);
	if (ft_strlen(map->g) == 1)
		map->g = ft_strjoin_free2("0", map->g);
	map->b = ft_itoa_base(map->rgb.b, 16);
	if (ft_strlen(map->b) == 1)
		map->b = ft_strjoin_free2("0", map->b);
	if (line[0] == 'F' && map->color_ceil[0] == '\0')
	{
		map->color_ceil = ft_strjoin_free(map->color_ceil, map->r);
		map->color_ceil = ft_strjoin_free(map->color_ceil, map->g);
		map->color_ceil = ft_strjoin_free(map->color_ceil, map->b);
	}
	else if (line[0] == 'C' && map->color_floor[0] == '\0')
	{
		map->color_floor = ft_strjoin_free(map->color_floor, map->r);
		map->color_floor = ft_strjoin_free(map->color_floor, map->g);
		map->color_floor = ft_strjoin_free(map->color_floor, map->b);
	}
	else
		print_error("Error:\nWhen take color map\n", map);
}

void	ft_take_color(char *line, t_map *map)
{
	int		i;

	i = 1;
	if (line[i] == ' ')
		i++;
	map->rgb.r = ft_atoi(&line[i]);
	while (line[i] == ' ' || ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	map->rgb.g = ft_atoi(&line[i]);
	while (line[i] == ' ' || ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	map->rgb.b = ft_atoi(&line[i]);
	ft_convert_rgb(line, map);
	map->floor = ft_atoi_base(map->color_floor, 16);
	map->ceil = ft_atoi_base(map->color_ceil, 16);
}

void	ft_take_spr(char c, t_map *map, int y, int j)
{
	map->map[y][j] = c - '0';
	if (map->map[y][j] > 1)
		dist_sprite(map, y, j);
}

void	ft_take_map(char *line, t_map *map)
{
	int				i;
	int				j;
	static int		y = 0;

	i = 0;
	j = 0;
	if (!(map->map[y] = ft_calloc(map->map_width, sizeof(int *))))
		print_error("Error:\nWhen you alloued map\n", map);
	while (line[i])
	{
		if (map_is_valide(line[i]) && line[i] != ' ')
			ft_take_spr(line[i], map, y, j++);
		else if (map_player_start(line[i]))
		{
			ft_check_multi_player_start(map, line[i]);
			map->map[y][j] = 0;
			map->player.pos.y = y + 0.5;
			map->player.pos.x = j + 0.5;
			j++;
		}
		i++;
	}
	y++;
}
