/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:29:11 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 11:23:56 by frfrey      ###    #+. /#+    ###.fr     */
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

int		changecolor(t_id *id)
{
	int x = 0;
	int y = 0;
	int *data;
	int bits = 0;
	int size = 0;
	int endian = 0;
	void	*image;

	id->color = id->color - 10000;
	image = mlx_new_image(id->mlx, 1920, 1080);
	data = (int *)mlx_get_data_addr(image, &bits, &size, &endian);
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			data[y * 1920 + x] = id->color + x;
			x++;
		}
		y++;
		id->color = id->color + 1;
	}
	mlx_put_image_to_window(id->mlx, id->windows, image, 0, 0);
	return (1);
}

int		main(int ac, char **av)
{
	t_id	id;

	(void)id;
	if (ac == 2)
		ft_open_map(av);
	else
		return (print_error("error: error: invalid map file"));
	/*if (!(id.mlx = mlx_init()))
		exit(EXIT_FAILURE);
	if (!(id.windows = mlx_new_window(id.mlx, 1920, 1080, "Cube3D")))
		exit(EXIT_FAILURE);
	mlx_loop_hook(id.mlx, changecolor, &id);
	mlx_key_hook(id.windows, deal_key, &id);
	mlx_hook(id.windows, 17, 0, try, &id);
	mlx_loop(id.mlx);*/
	return (0);
}
