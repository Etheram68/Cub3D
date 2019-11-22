/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:29:11 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 11:38:11 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		try(t_id *id)
{
	mlx_clear_window(id->mlx, id->windows);
	if (!(mlx_destroy_window(id->mlx, id->windows)))
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return (1);
}

int		deal_key(int key, t_id *params)
{
	if (key == 53)
		try(params);
	return (1);
}

int		main(void)
{
	t_id	id;
	void	*image;
	int bits = 0;
	int size = 0;
	int endian = 0;
	int *data;
	int x = 0;
	int y = 0;

	if (!(id.mlx = mlx_init()))
		exit(EXIT_FAILURE);
	if (!(id.windows = mlx_new_window(id.mlx, 1920, 1080, "Cube3D")))
		exit(EXIT_FAILURE);
	image = mlx_new_image(id.mlx, 1920, 1080);
	data = (int *)mlx_get_data_addr(image, &bits, &size, &endian);
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			if(x > 960)
				data[y * 1920 + x] = 0xff00;
			else
				data[y * 1920 + x] = 0xff;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(id.mlx, id.windows, image, 0, 0);
	mlx_key_hook(id.windows, deal_key, &id);
	mlx_hook(id.windows, 17, 0, try, &id);
	mlx_loop(id.mlx);
	return (0);
}
