/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:34:09 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*tmp_src;
	char		*tmp_dest;

	if (!dest && !src)
		return (NULL);
	tmp_src = src;
	tmp_dest = dest;
	if (tmp_dest <= tmp_src)
		while (n--)
			*tmp_dest++ = *tmp_src++;
	else
		while (n--)
			*(tmp_dest + n) = *(tmp_src + n);
	return (dest);
}
