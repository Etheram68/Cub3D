/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:29:11 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 13:42:52 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		try(t_map *map)
{
	mlx_clear_window(map->id.mlx, map->id.windows);
	if (!(mlx_destroy_window(map->id.mlx, map->id.windows)))
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_open_map(av);
	else
		return (print_error("Error:\nInvalid map file\n"));
	/*while (1)
		;*/
	return (0);
}
