/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_nb.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:40:51 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:22 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_pf_nbflags(long nb, int fd, t_pf_lst *lst)
{
	long temp;

	temp = nb;
	if (nb < 0 && (!ft_have(lst->flags, '0') || ft_have(lst->flags, '-')))
		ft_putchar_fd('-', fd);
	if (nb < 0 && ft_have(lst->flags, '0')
		&& ft_have(lst->p_flag, '.') && !ft_have(lst->flags, '-'))
		ft_putchar_fd('-', fd);
	if (ft_have(lst->flags, '+') && nb >= 0)
		ft_putchar_fd('+', fd);
	else if (ft_have(lst->flags, ' ') && nb >= 0)
		ft_putchar_fd(' ', fd);
	while (lst->p_value > ft_intlen(temp > 0 ? temp : -temp))
	{
		ft_putchar_fd('0', fd);
		lst->p_value--;
	}
	if (nb == 0 && ft_have(lst->p_flag, '.') && lst->p_value == 0)
		return ;
	ft_putnbr_fd(temp > 0 ? temp : -temp, 1);
}

void	ft_pf_hexflags(long long nb, int fd, t_pf_lst *lst)
{
	long long temp;

	temp = nb;
	if (nb < 0 && lst->type != 'p'
		&& (!ft_have(lst->flags, '0') || ft_have(lst->flags, '-')))
		ft_putchar_fd('-', fd);
	if (nb < 0 && ft_have(lst->flags, '0')
		&& ft_have(lst->p_flag, '.') && !ft_have(lst->flags, '-'))
		ft_putchar_fd('-', fd);
	else if (ft_have(lst->flags, ' ') && nb >= 0)
		ft_putchar_fd(' ', fd);
	if (lst->type == 'p')
		ft_putstr_fd("0x", fd);
	while (lst->p_value > ft_hexlen(temp))
	{
		ft_putchar_fd('0', fd);
		lst->p_value--;
	}
	if (nb == 0 && ft_have(lst->p_flag, '.') && lst->p_value == 0)
		return ;
	if (lst->type == 'X')
		ft_tohexhigh_fd(nb, fd);
	else
		ft_tohexlow_fd(nb, fd);
}

int		ft_pf_putnbr_fd(long long nb, int fd, t_pf_lst *lst)
{
	int		ilen;
	char	c;

	c = ' ';
	ilen = ft_intlen(nb < 0 ? -nb : nb);
	ilen < lst->p_value ? ilen = lst->p_value : ilen;
	if (ft_have(lst->flags, '0') && !ft_have(lst->flags, '-')
		&& !ft_have(lst->p_flag, '.'))
		c = '0';
	if (ft_have(lst->flags, '+') || ft_have(lst->flags, ' ') || nb < 0)
		ilen++;
	if (ft_have(lst->flags, '-'))
	{
		ft_pf_nbflags(nb, fd, lst);
		ilen = ft_pf_printf_width(lst, ilen, c, nb);
	}
	else
	{
		if (nb < 0 && ft_have(lst->flags, '0') && !ft_have(lst->p_flag, '.'))
			ft_putchar_fd('-', fd);
		ilen = ft_pf_printf_width(lst, ilen, c, nb);
		ft_pf_nbflags(nb, fd, lst);
	}
	return (ilen);
}

int		ft_put_hex_fd(t_pf_lst *lst, long long nb, int fd)
{
	int		ilen;
	char	c;

	c = ' ';
	ilen = ft_hexlen(nb);
	ilen < lst->p_value ? ilen = lst->p_value : ilen;
	if (ft_have(lst->flags, '0') && !ft_have(lst->flags, '-')
		&& !ft_have(lst->p_flag, '.'))
		c = '0';
	if (ft_have(lst->flags, '-'))
	{
		ft_pf_hexflags(nb, fd, lst);
		ilen = ft_pf_printf_width(lst, ilen, c, nb);
	}
	else
	{
		if (nb < 0 && ft_have(lst->flags, '0') && !ft_have(lst->p_flag, '.'))
			ft_putchar_fd('-', fd);
		ilen = ft_pf_printf_width(lst, ilen, c, nb);
		ft_pf_hexflags(nb, fd, lst);
	}
	return (ilen + (lst->type == 'p' ? 2 : 0));
}
