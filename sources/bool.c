/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bool.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 11:28:03 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 12:13:47 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_cube3d.h"

int		map_is_valide(char c)
{
	if (c == '0' || c == '1' || c == '2')
		return (TRUE);
	return (FALSE);
}

int		map_player_start(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

int		is_texture(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'O'
		|| c == 'A' || c == ' ')
		return (TRUE);
	return (FALSE);
}

int		ft_is_border(int nb, t_map *map)
{
	if (nb == 1)
		return (TRUE);
	print_error("Error:\nThe border is not a wall\n", map);
	return (FALSE);
}

void	ft_resize_winows(t_map *map)
{
	if (map->w_height < 100)
	{
		ft_putstr_fd(
			"Warning:\nHeight is less of 100, it has been resized to 100\n", 1);
		map->w_height = 100;
	}
	if (map->w_width < 100)
	{
		ft_putstr_fd(
			"Warning:\nWidth is less of 100, it has been resized to 100\n", 1);
		map->w_width = 11;
	}
}
