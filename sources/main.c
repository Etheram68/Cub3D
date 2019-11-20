/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:29:11 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 16:18:10 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		main(void)
{
	void	*mlx;
	void	*widows;

	mlx = mlx_init();
	widows = mlx_new_window(mlx, 800, 600, "Cube3D");
	mlx_loop(widows);
	return (0);
}
