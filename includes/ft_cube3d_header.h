/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cube3d_header.h                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:04:51 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 18:13:10 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_CUBE3D_HEADER_H
# define FT_CUBE3D_HEADER_H

# include "ft_cube3d_struct.h"

int		deal_key(int key, t_id *params);
int		print_error(char *str);
void	ft_init_struct(t_map *map);
int		ft_open_map(char **av);
int		ft_count_size_map(int fd, t_map *map);
int		try(t_id *id);
int		map_is_valide(char c);
int		map_player_start(char c);
void	ft_count_heigth_map(char *line, int *size_map);
void	ft_count_len_map(char *line, int *len_map, t_map *map);
int		ft_parse_map(int fd, t_map *map);
int		is_texture(char c);
void	ft_size_windows(char *line, t_map *map);
void	ft_texture_north(char *line, t_map *map);
void	ft_check_texture(char *line, t_map *map);
void	ft_take_color(char *line, t_map *map);
void	ft_convert_rgb(char *line, t_map *map);

#endif
