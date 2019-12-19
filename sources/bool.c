/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bool.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 11:28:03 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 15:17:22 by frfrey      ###    #+. /#+    ###.fr     */
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

int		ft_is_border(char c, t_map *map)
{
	if (c == 1)
		return (TRUE);
	print_error("Error:\nThe border is not a wall\n", map);
	return (FALSE);
}
