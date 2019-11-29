/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 17:25:42 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 17:51:46 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_is_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
		if (base[i++] == c)
			return (TRUE);
	return (FALSE);
}

static int		ft_get_base(char c, char *base)
{
	int		i;

	i = 0;
	while (c != base[i])
		i++;
	return (i);
}

int		ft_atoi_base(const char *str, int base)
{
	int		i;
	size_t	nb;
	int		is_neg;
	char	*nb_base;

	i = 0;
	is_neg = 1;
	nb = 0;
	nb_base = "0123456789ABCDEF";
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_is_base(str[i], nb_base))
		nb = nb * base + (ft_get_base(str[i++], nb_base));
	return (nb * is_neg);
}
