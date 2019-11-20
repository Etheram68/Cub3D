/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_bool.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:43:37 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:29 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	ft_pf_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'n' || c == 'f' || c == 'g' || c == 'e'
		|| c == '%')
		return (TRUE);
	return (FALSE);
}

int		ft_pf_isconverter(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 'l' || str[i] == 'h')
		i++;
	return (i);
}

char	ft_pf_isprecision(char c)
{
	if (c == '*' || c == '.')
		return (TRUE);
	return (FALSE);
}

char	ft_pf_isflag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (TRUE);
	return (FALSE);
}
