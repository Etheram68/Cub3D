/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 12:05:22 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_set(char c, const char *set)
{
	int i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (TRUE);
	return (FALSE);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		trim;
	char	*str;

	i = 0;
	trim = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	while (is_set(s1[i], set))
		i++;
	while ((size_t)i++ < ft_strlen(s1))
		trim++;
	while (is_set(s1[--i - 1], set) && trim != 0)
		trim--;
	if (!(str = (char *)malloc(sizeof(*str) * (trim + 1))))
		return (NULL);
	i = 0;
	while (is_set(*s1, set))
		s1++;
	while (trim--)
		str[i++] = *s1++;
	str[i] = '\0';
	return (str);
}
