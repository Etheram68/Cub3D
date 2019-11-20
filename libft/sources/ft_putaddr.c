/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putaddr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 14:27:11 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		get_nb_addr(long n)
{
	int cpt;

	cpt = 0;
	if (n <= 0)
		cpt++;
	while (n != 0)
	{
		cpt++;
		n /= 16;
	}
	return (cpt + 2);
}

static void		putnbr_addr(char *str, long n, int last_index)
{
	long nb;

	nb = n;
	if (nb > 15)
		putnbr_addr(str, nb / 16, last_index - 1);
	str[last_index] = nb % 16 + '0';
}

char			*ft_putaddr(unsigned long n)
{
	char	*str;
	int		nb_char;
	char	*nb_base;
	int		i;

	i = 2;
	nb_char = get_nb_addr(n);
	nb_base = "0123456789abcdef";
	if (!(str = malloc(sizeof(char) * (nb_char + 1))))
		return (0);
	str[nb_char] = '\0';
	putnbr_addr(str, n, nb_char - 1);
	while (str[i])
	{
		str[i] = nb_base[str[i] - '0'];
		i++;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}
