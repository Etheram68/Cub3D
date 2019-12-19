/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_string.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:37:08 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:24 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_pf_putchar_fd(char d, int fd, t_pf_lst *lst)
{
	int		i;
	char	c;

	i = -1;
	c = ' ';
	if (ft_have(lst->flags, '0') && !ft_have(lst->flags, '-'))
		c = '0';
	lst->w == 0 ? lst->w++ : lst->w;
	if (ft_have(lst->flags, '-'))
	{
		write(fd, &d, 1);
		ft_pf_printf_width(lst, 1, c, 1);
	}
	else
	{
		ft_pf_printf_width(lst, 1, c, 1);
		write(fd, &d, 1);
	}
	if (lst->w == -2147483648)
		return (1);
	return (lst->w);
}

int		ft_pf_putstr_fd(char *str, int fd, t_pf_lst *lst)
{
	int		i;
	char	*nstr;
	char	c;

	i = -1;
	c = ' ';
	!str ? str = ft_strdup("(null)") : 0;
	nstr = NULL;
	if (lst->p_value > (int)ft_strlen(str) || lst->p_value == -1)
		lst->p_value = ft_strlen(str);
	if (ft_have(lst->flags, '0') && !ft_have(lst->flags, '-'))
		c = '0';
	if (lst->w >= lst->p_value)
	{
		if (!(nstr = malloc(sizeof(char) * (lst->w + 1 - lst->p_value))))
			return (0);
		while (lst->w + 1 - lst->p_value > 0 && ++i < lst->w - lst->p_value)
			nstr[i] = c;
		nstr[i] = 0;
	}
	if (ft_have(lst->flags, '-'))
		ft_putjoinfree(ft_strdupnb(str, lst->p_value), nstr, fd);
	else
		ft_putjoinfree(nstr, ft_strdupnb(str, lst->p_value), fd);
	return (lst->w > lst->p_value ? lst->w : lst->p_value);
}
