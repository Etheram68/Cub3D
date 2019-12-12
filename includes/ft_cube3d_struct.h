/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cube3d_struct.h                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 10:39:38 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 19:00:40 by frfrey      ###    #+. /#+    ###.fr     */
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
	double	x;
	double	y;
}				t_vectord;

typedef struct	s_id
{
	void	*mlx;
	void	*windows;
	int		color;
	void	*image;
	int		*data;
	int		line;
	int		bits;
	int		endian;
	double	fps;
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
	int			len;
	int			sprite;
}				t_rayon;

typedef struct	s_player
{
	t_vectord	dir;
	t_vectord	plane;
	t_vectord	pos;
	int			w;
	int			s;
	int			a;
	int			d;
	int			leftarrow;
	int			rightarrow;
	int			shift;
	double		speed_move;
	double		speed_rot;
}				t_player;

typedef	struct	s_tex
{
	void		*image;
	int			*data;
	int			bits;
	int			line;
	int			endian;
	int			size;
}				t_tex;

typedef struct	s_wall
{
	int			tex_x;
	int			tex_y;
	double		wall;
}				t_wall;

typedef struct	s_map
{
	int			**map;
	int			map_heigth;
	int			map_width;
	int			w_height;
	int			w_width;
	char		*t_north;
	char		*t_south;
	char		*t_west;
	char		*t_east;
	char		*sprite;
	char		*color_ceil;
	char		*color_floor;
	long		floor;
	long		ceil;
	t_color		rgb;
	t_player	player;
	t_id		id;
	t_rayon		ray;
	char		dir;
	t_wall		wall;
	t_tex		tex[4];
}				t_map;

#endif
