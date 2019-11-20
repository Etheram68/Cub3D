/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tohexhigh_fd.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:14:56 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len(long long nb)
{
	int len;

	len = 0;
	nb < 0 ? len++ : len;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	len == 0 ? len++ : len;
	return (len);
}

int			ft_tohexhigh_fd(unsigned long n, int fd)
{
	char			*hexc;
	unsigned long	secu;

	hexc = "0123456789ABCDEF";
	secu = n;
	if (secu > 15)
	{
		ft_tohexhigh_fd(secu / 16, fd);
		ft_putchar_fd(hexc[secu % 16], fd);
	}
	else
		ft_putchar_fd(hexc[secu % 16], fd);
	return (ft_len(n));
}
