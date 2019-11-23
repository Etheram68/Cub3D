/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_free2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 18:04:59 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 18:05:44 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free2(char *s1, char *s2)
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
		free(s2);
		return (str);
	}
	return (0);
}
