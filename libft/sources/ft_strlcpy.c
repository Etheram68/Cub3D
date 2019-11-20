/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:37:50 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (0);
	if ((int)size == 0)
		return (ft_strlen(src));
	while (src[i] && i < ((int)size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
