/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_to_string.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/09 19:20:18 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_to_string(char c)
{
	char	*str;

	if (!(str = malloc(sizeof(*str) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
