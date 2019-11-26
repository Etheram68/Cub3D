/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cube3d_struct.h                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 10:39:38 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 10:03:24 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_CUBE3D_STRUCT_H
# define FT_CUBE3D_STRUCT_H

typedef	struct	s_vectori
{
	int		x;
	int		y;
}				t_vectori;

typedef struct	s_vectord
{
	float	x;
	float	y;
}				t_vectord;

typedef struct	s_id
{
	void	*mlx;
	void	*windows;
	int		color;
	void	*image;
}				t_id;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_rayon
{
	t_vectord	pos;
	t_vectord	dir;
	t_vectori	map;
	t_vectord	side;
	t_vectord	delta;
	t_vectori	step;
	double		dist;
	double		cam;
	int			hit;
	int			hit_side;

}				t_rayon;

typedef struct	s_player
{
	t_vectord	dir;
	t_vectord	plane;
	t_vectord	pos;
}				t_player;

typedef struct	s_map
{
	char		**map;
	int			map_heigth;
	int			map_width;
	int			w_height;
	int			w_width;
	char		*t_north;
	char		*t_south;
	char		*t_west;
	char		*t_east;
	char		*sprite;
	char		*color_top;
	char		*color_foot;
	t_color		rgb;
	t_player	player;
	t_id		id;
	t_rayon		ray;
}				t_map;

#endif
