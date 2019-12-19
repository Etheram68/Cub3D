/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tohexlow_fd.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:15:30 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len(unsigned long nb)
{
	int len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	len == 0 ? len++ : len;
	return (len);
}

int			ft_tohexlow_fd(unsigned long n, int fd)
{
	char			*hexc;
	unsigned long	secu;

	hexc = "0123456789abcdef";
	secu = n;
	if (secu > 15)
	{
		ft_tohexlow_fd(secu / 16, fd);
		ft_putchar_fd(hexc[secu % 16], fd);
	}
	else
		ft_putchar_fd(hexc[secu % 16], fd);
	return (ft_len(n));
}
