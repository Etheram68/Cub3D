/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/09 19:47:41 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		get_nb_char_base(long n, int base)
{
	int cpt;

	cpt = 0;
	if (n <= 0)
		cpt++;
	while (n != 0)
	{
		cpt++;
		n /= base;
	}
	return (cpt);
}

static void		putnbr_itoa_base(char *str, long n, int base, int last_index)
{
	long nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb > base - 1)
		putnbr_itoa_base(str, nb / base, base, last_index - 1);
	str[last_index] = nb % base + '0';
}

char			*ft_itoa_base(long n, int base)
{
	char	*str;
	int		nb_char;
	char	*nb_base;
	int		i;

	i = 0;
	nb_char = get_nb_char_base(n, base);
	nb_base = "0123456789ABCDEF";
	if (!(str = malloc(sizeof(char) * (nb_char + 1))))
		return (0);
	str[nb_char] = '\0';
	if (n < 0)
		str[0] = '-';
	putnbr_itoa_base(str, n, base, nb_char - 1);
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		str[i] = nb_base[str[i] - '0'];
		i++;
	}
	return (str);
}
