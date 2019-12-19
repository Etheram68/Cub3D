/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 09:51:34 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>

static char		*ft_strjoin_gnl(char *s1, char *s2, size_t len)
{
	size_t		i;
	size_t		y;
	char		*str;

	i = 0;
	y = 0;
	if (s1 || s2)
	{
		if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + len + 1))))
			return (NULL);
		while (s1 && s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2 && s2[y] && len--)
			str[i++] = s2[y++];
		str[i] = '\0';
		free(s1);
		return (str);
	}
	return (0);
}

static char		*ft_strdup_gnl(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	if (!src || src[i] == '\0')
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int		check_rest(char **str, char **line)
{
	int		i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*line = ft_strjoin_gnl(*line, *str, i)))
		return (-1);
	if ((*str)[i] == '\0')
	{
		free(*str);
		return (0);
	}
	if ((*str)[i] == '\n' && (*str)[i + 1] == '\0')
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	i++;
	ft_memmove(*str, *str + i, ft_strlen(*str + i) + 1);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*str = NULL;
	char			file[BUFFER_SIZE + 1];
	int				ret;
	int				i;

	if (fd < 0 || !line || read(fd, file, 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strnew("");
	if (!*line || (str && *str != '\0' && (i = check_rest(&str, line))))
		return ((!*line || i < 0) ? -1 : 1);
	while ((ret = read(fd, file, BUFFER_SIZE)))
	{
		i = 0;
		file[ret] = '\0';
		while (file[i] && file[i] != '\n')
			i++;
		if (!(*line = ft_strjoin_gnl(*line, file, i)))
			return (-1);
		if (file[i] == '\n')
		{
			str = ft_strdup_gnl(file + ++i);
			return (1);
		}
	}
	return (0);
}
