/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_flag.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 14:10:36 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:19 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_pf_printf_width(t_pf_lst *lst, int ilen, char c, long long nb)
{
	if (nb == 0 && ft_have(lst->p_flag, '.') && lst->p_value == 0)
		ilen = 0;
	if (lst->type == 'p')
		lst->w -= 2;
	while (lst->w > ilen)
	{
		ft_putchar_fd(c, 1);
		ilen++;
	}
	return (ilen);
}
