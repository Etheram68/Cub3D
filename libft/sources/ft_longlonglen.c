/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_longlonglen.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:12:28 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_longlonglen(long long nb)
{
	int len;

	len = 0;
	nb < 0 ? len++ : len;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	len == 0 ? len++ : len;
	return (len);
}
