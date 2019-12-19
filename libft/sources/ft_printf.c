/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 10:33:24 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:38 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_pf_lst	*lst;
	t_pf_lst	*temp;
	int			i;

	lst = NULL;
	i = 0;
	va_start(ap, format);
	lst = ft_parse((char*)format, ap);
	i = ft_pf_print(format, lst, ap);
	va_end(ap);
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	return (i);
}
