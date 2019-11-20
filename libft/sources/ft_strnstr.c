/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:14:30 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	nb_count;
	size_t	nb_len;

	i = -1;
	nb_len = 0;
	if (!src)
		return (NULL);
	if (!find || *find == '\0')
		return ((char *)src);
	nb_len = ft_strlen(find);
	while (src[++i] && i <= n)
		if (src[i] == find[0])
		{
			j = -1;
			nb_count = 0;
			while (src[i + ++j] && find[j] && i + j < n)
				if (src[i + j] == find[j])
					nb_count++;
			if (nb_count == nb_len)
				return ((char *)src + i);
		}
	return (NULL);
}
