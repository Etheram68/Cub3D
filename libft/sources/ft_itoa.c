/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 13:09:23 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		get_nb_char(long n)
{
	int cpt;

	cpt = 0;
	if (n <= 0)
		cpt++;
	while (n != 0)
	{
		cpt++;
		n /= 10;
	}
	return (cpt);
}

static void		putnbr_itoa(char *str, long n, int last_index)
{
	long nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb > 9)
		putnbr_itoa(str, nb / 10, last_index - 1);
	str[last_index] = nb % 10 + '0';
}

char			*ft_itoa(long n)
{
	char	*str;
	int		nb_char;

	nb_char = get_nb_char(n);
	if (!(str = malloc(sizeof(char) * (nb_char + 1))))
		return (0);
	str[nb_char] = '\0';
	if (n < 0)
		str[0] = '-';
	putnbr_itoa(str, n, nb_char - 1);
	return (str);
}
