/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putjoinfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:19:24 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putjoinfree(char *s1, char *s2, int fd)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	if (!(join = malloc(i + j + 1)))
		return ;
	i = -1;
	j = -1;
	while (++i >= 0 && s1 && s1[i])
		join[i] = s1[i];
	while (++j >= 0 && s2 && s2[j])
		join[i + j] = s2[j];
	join[i + j] = 0;
	ft_putstr_fd(join, fd);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	free(join);
}
