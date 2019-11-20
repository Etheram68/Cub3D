/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 10:35:54 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (0);
	if (!(start > ft_strlen(s) || len == 0))
	{
		if (len > ft_strlen(s + start))
			len = ft_strlen(s + start);
		if (!(str = (char *)malloc(sizeof(*str) * ((len + 1)))))
			return (NULL);
		while (len-- && s[start])
			str[i++] = s[start++];
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(*str) * 1)))
			return (NULL);
	}
	str[i] = '\0';
	return (str);
}
