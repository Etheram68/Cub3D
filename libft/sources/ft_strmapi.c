/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 15:10:31 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s && f)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
