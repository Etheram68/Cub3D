/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 17:04:15 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 18:07:23 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

void	ft_size_windows(char *line, t_map *map)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
			map->w_width = ft_atoi(&line[++i]);
		if (line[i] == ' ')
			i++;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (ft_isdigit(line[++i]))
			map->w_height = ft_atoi(&line[i]);
	}
	if (map->w_height == 0 || map->w_width == 0)
		print_error("Error:\nSize of windows is invalid\n");
}

void	ft_convert_rgb(char *line, t_map *map)
{
	char	*r;
	char	*g;
	char	*b;

	r = ft_itoa_base(map->rgb.r, 16);
	if (ft_strlen(r) == 1)
		r = ft_strjoin_free2("0", r);
	g = ft_itoa_base(map->rgb.g, 16);
	if (ft_strlen(g) == 1)
		g = ft_strjoin_free2("0", g);
	b = ft_itoa_base(map->rgb.b, 16);
	if (ft_strlen(b) == 1)
		b = ft_strjoin_free2("0", b);
	if (line[0] == 'F')
	{
		map->color_ceil = ft_strjoin_free(map->color_ceil, r);
		map->color_ceil = ft_strjoin_free(map->color_ceil, g);
		map->color_ceil = ft_strjoin_free(map->color_ceil, b);
	}
	else if (line[0] == 'C')
	{
		map->color_floor = ft_strjoin_free(map->color_floor, r);
		map->color_floor = ft_strjoin_free(map->color_floor, g);
		map->color_floor = ft_strjoin_free(map->color_floor, b);
	}
}

void	ft_take_color(char *line, t_map *map)
{
	int		i;

	i = 1;
	if (line[i] == ' ')
		i++;
	map->rgb.r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	map->rgb.g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	map->rgb.b = ft_atoi(&line[i]);
	ft_convert_rgb(line, map);
}

void	ft_take_map(char *line, t_map *map)
{
	int				i;
	int				j;
	static int		y = 0;

	i = 0;
	j = 0;
	if (!(map->map[y] = ft_calloc(map->map_width + 1, sizeof(char *))))
		print_error("Error:\nWhen you alloued map\n");
	while (line[i])
	{
		if (map_is_valide(line[i]))
			map->map[y][j] = line[i++];
		if (map_player_start(line[i]))
		{
			ft_check_multi_player_start(map);
			map->map[y][j] = '0';
			map->player.pos.x = y + 0.5;
			map->player.pos.y = j + 0.5;
			i++;
		}
		if (line[i] == ' ')
			i++;
		j++;
	}
	y++;
}
