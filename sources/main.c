/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:29:11 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 14:05:27 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		try(void)
{
	exit(EXIT_SUCCESS);
	return (1);
}

int		main(void)
{
	void	*mlx;
	void	*windows;
	void	*image;
	int bits = 0;
	int truc = 0;
	int truc2 = 0;
	int *data;
	int x = 0;
	int y = 0;

	if (!(mlx = mlx_init()))
		exit(EXIT_FAILURE);
	if (!(windows = mlx_new_window(mlx, 1920, 1080, "Cube3D")))
		exit(EXIT_FAILURE);
	image = mlx_new_image(mlx, 1920, 1080);
	data = (int *)mlx_get_data_addr(image, &bits, &truc, &truc2);
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			if(y > 540)
				data[y * 1920 + x] = 0xff00;
			else
				data[y * 1920 + x] = 0xff;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, windows, image, 0, 0);
	mlx_hook (windows, 17, 0, try, NULL);
	mlx_loop(mlx);
	return (0);
}
