/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_print.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:40:06 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:35 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_pf_print_type(t_pf_lst *lst, va_list ap)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (lst->type == 'c')
		i += ft_pf_putchar_fd((int)va_arg(ap, int), 1, lst);
	if (lst->type == 's')
		i += ft_pf_putstr_fd((char*)va_arg(ap, char*), 1, lst);
	if (lst->type == 'p')
		i += ft_put_hex_fd(lst, (unsigned long)va_arg(ap, unsigned long), 1);
	if (lst->type == 'd' || lst->type == 'i')
		i += ft_pf_putnbr_fd((int)va_arg(ap, int), 1, lst);
	if (lst->type == 'u')
		i += ft_pf_putnbr_fd((unsigned int)va_arg(ap, unsigned int), 1, lst);
	if (lst->type == 'x' || lst->type == 'X')
		i += ft_put_hex_fd(lst, (unsigned int)va_arg(ap, unsigned int), 1);
	if (lst->type == '%')
		i += ft_pf_putchar_fd('%', 1, lst);
	return (i);
}

int	ft_pf_print_format(const char **format)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*format)[j])
	{
		if ((*format)[j] == '%')
		{
			if ((*format)[j + 1] == 0)
				break ;
			else if (!ft_pf_istype((*format)[j + 1])
				&& !ft_pf_isflag((*format)[j + 1])
				&& !ft_pf_isprecision((*format)[j + 1])
				&& !ft_isdigit((*format)[j + 1]))
				j++;
			else
				break ;
		}
		i++;
		ft_putchar_fd((*format)[j], 1);
		j++;
	}
	*format += j;
	return (i);
}

int	ft_pf_print_parsed(t_pf_lst *lst, va_list ap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	i = ft_pf_print_type(lst, ap);
	return (i);
}

int	ft_pf_print(const char *format, t_pf_lst *lst, va_list ap)
{
	int i;

	i = 0;
	while (lst)
	{
		i += ft_pf_print_format(&format);
		i += ft_pf_print_parsed(lst, ap);
		format += lst->len + 1;
		lst = lst->next;
	}
	i += ft_pf_print_format(&format);
	return (i);
}
