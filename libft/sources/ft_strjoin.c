/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 11:38:22 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		y;
	char		*str;

	i = 0;
	y = 0;
	if (s1 || s2)
	{
		if (!(str = (char *)malloc(sizeof(*str) *
				((ft_strlen(s1) + ft_strlen(s2)) + 1))))
			return (NULL);
		while (s1 && s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2 && s2[y])
			str[i++] = s2[y++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}
