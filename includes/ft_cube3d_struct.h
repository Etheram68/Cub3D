/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cube3d_struct.h                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 10:39:38 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 13:48:04 by frfrey      ###    #+. /#+    ###.fr     */
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
	int			start;
	int			end;
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

typedef struct	s_sprite
{
	t_vectord	pos;
	int			type;
	int			order;
	double		dist;
}				t_sprite;

typedef struct	s_sprcast
{
	t_vectord	sprite;
	t_vectord	form;
	double		multi;
	int			screen;
	t_vectori	start;
	t_vectori	end;
	t_vectori	tex;
	int			s_height;
	int			s_width;
	int			save;
}				t_sprcast;

typedef struct	s_bitmap_file_header
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}				t_bfh;

typedef struct	s_bitmap_image_header
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_bih;

typedef struct	s_map
{
	t_sprcast	csp;
	int			**map;
	int			save;
	int			map_heigth;
	int			map_width;
	int			w_height;
	int			w_width;
	int			spr_i;
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
	char		*r;
	char		*g;
	char		*b;
	t_sprite	spr[50];
	t_tex		tex[10];
	int			order[50];
	double		dist[50];
}				t_map;

#endif
