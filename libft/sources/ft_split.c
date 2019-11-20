/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 16:03:10 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		count_words(const char *str, char sep)
{
	int i;
	int nb_sep;

	i = 0;
	nb_sep = 0;
	while (str[i])
	{
		if (str[i] == sep && str[i + 1] != sep && str[i])
			nb_sep++;
		if (str[i] && str[i] != sep)
			nb_sep++;
		while (str[i + 1] != sep
				&& str[i] && str[i + 1] != '\0')
			i++;
		i++;
		while (str[i] && str[i] == sep)
			i++;
	}
	return (nb_sep);
}

static int		ft_strlen_sep(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char		*ft_strdup_split(const char *s, char c)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(tab = ft_calloc(sizeof(char), (ft_strlen_sep(s, c) + 1))))
		return (NULL);
	while (*s && *s != c)
	{
		tab[i] = *s;
		s++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char		*ft_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char		**tab;
	int			i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(tab = ft_calloc(sizeof(tab), (count_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			tab[++i] = ft_strdup_split(s, c);
			if (tab[i] == NULL)
				return ((char **)ft_free(tab));
			while (*s && *s != c)
				s++;
		}
		while (*s == c && *s)
			s++;
	}
	tab[i + 1] = NULL;
	return (tab);
}
