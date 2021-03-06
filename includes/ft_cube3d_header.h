/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cube3d_header.h                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 10:04:51 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 20:16:29 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_CUBE3D_HEADER_H
# define FT_CUBE3D_HEADER_H

# include "ft_cube3d_struct.h"

/*
**				Init Struct						**
*/

void	ft_init_struct(t_map *map);
void	ft_init_player(t_map *map);
void	ft_init_id(t_map *map);
void	ft_init_dir_player(t_map *map);
void	ft_init_dir_player_ew(t_map *map);
void	ft_init_tex(t_map *map);
void	ft_init_texture(t_map *map);
void	ft_init_sprite(t_map *map);

/*
**				Open Map and parse				**
*/

int		ft_open_map(char **av, t_map *map);
int		ft_count_size_map(int fd, t_map *map);
void	ft_count_heigth_map(char *line, int *size_map);
void	ft_count_len_map(char *line, int *len_map, t_map *map);
int		ft_parse_map(int fd, t_map *map);
void	ft_size_windows(char *line, t_map *map);
void	ft_texture_north(char *line, t_map *map);
void	ft_take_color(char *line, t_map *map);
void	ft_convert_rgb(char *line, t_map *map);
void	ft_take_spr(char c, t_map *map, int y, int j);
void	ft_take_map(char *line, t_map *map);
void	ft_texture(char *line, t_map *map);
void	ft_check_type(char *line, t_map *map);

/*
**						Bool					**
*/

int		is_texture(char c);
int		map_is_valide(char c);
int		ft_is_border(int nb, t_map *map);
int		map_player_start(char c);

/*
**				Check parsing					**
*/

void	ft_check_texture(char *line, t_map *map);
void	ft_check_multi_player_start(t_map *map, char dir);
void	ft_check_player_start(t_map *map);
void	ft_check_map_is_valide(t_map *map);
void	ft_resize_winows(t_map *map);

/*
**				Raycasting						**
*/

int		ft_raycasting(t_map *map);
void	init_rayon(t_map *map, int x);
void	rayon_side(t_map *map);
void	rayon_dist(t_map *map);
void	draw(t_map *map, int x);
void	dist_wall(t_map *map);

/*
**				Gestion Sprite					**
*/

void	dist_sprite(t_map *map, int y, int x);
void	draw_sprite(t_map *map, int y, unsigned int c);
void	draw_line_spr(t_map *map);
void	calc_sprite(t_map *map, int i);
void	draw_spr(t_map *map, double *size);
void	ft_calc_dist_spr(t_map *map);
void	ft_sort_spr(t_map *map);
int		ft_check_tex(char *tex);

/*
**				Draw map						**
*/

void	draw_line(t_map *map, int x);
void	draw_wall(t_map *map, int x, int y, unsigned int c);
void	calc_wall(t_map *map, int i);

/*
**			Gestion of move for player 			**
*/

int		ft_releaseinput(int i, t_map *map);
int		ft_holdinput(int key, t_map *map);
int		deal_key(t_map *map);
void	ft_move_up_down(t_map *map);
void	ft_move_left_rigth(t_map *map);
void	ft_move_cam_rigth(t_map *map);
void	ft_move_cam_left(t_map *map);

/*
**					Print Error					**
*/
int		print_error(char *str, t_map *map);
void	ft_free_struct(t_map *map);
int		print_error_nf(char *str, t_map *map);
int		try(t_map *map);

/*
**					Bitmap				**
*/
void	init_bitmap(t_map *map);
void	save_bitmap(char *filename, t_map *map);
void	bitmap_image(t_map *map, int fd, t_bih bih);

#endif
