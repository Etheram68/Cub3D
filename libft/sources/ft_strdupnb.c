/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdupnb.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:16:26 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdupnb(char *s, size_t nb)
{
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && i < nb)
		i++;
	if (!(dup = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && i < nb)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	if (ft_strncmp(s, "(null)", 6) == 0)
		free(s);
	return (dup);
}
