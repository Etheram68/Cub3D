/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_assign.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:44:18 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:27 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_pf_assignconverter(char *parsed, t_pf_lst *lst)
{
	int i;

	i = ft_pf_isconverter(parsed);
	lst->converter[i] = 0;
	while (--i >= 0)
		lst->converter[i] = parsed[i];
}

char	*ft_pf_assignprecision(char *parsed, t_pf_lst *lst, va_list ap)
{
	int		i;
	long	j;

	i = 0;
	while (ft_pf_isprecision(parsed[i]) && parsed[i] != '*')
	{
		lst->p_flag[i] = parsed[i];
		i++;
	}
	lst->p_flag[i] = 0;
	parsed += i;
	i = 0;
	if (*parsed == '*')
	{
		j = (int)va_arg(ap, int);
		j < 0 ? j = -1 : j;
		lst->p_value = j;
		return (parsed + 1);
	}
	if (ft_isdigit(*parsed))
		lst->p_value = ft_atoi(parsed);
	while (ft_isdigit(parsed[i]))
		i++;
	return (parsed + i);
}

char	*ft_pf_assignwidth(char *parsed, t_pf_lst *lst, va_list ap)
{
	int i;
	int	j;

	i = 0;
	if (*parsed == '*')
	{
		j = (int)va_arg(ap, int);
		if (j < 0)
		{
			j *= -1;
			while (lst->flags[i])
				i++;
			lst->flags[i] = '-';
		}
		lst->w = j;
		return (parsed + 1);
	}
	i = 0;
	lst->w = ft_atoi(parsed);
	while (ft_isdigit(parsed[i]))
		i++;
	return (parsed + i);
}

char	*ft_pf_assignflag(char *parsed, t_pf_lst *lst)
{
	int i;

	i = 0;
	while (ft_pf_isflag(parsed[i]))
		i++;
	i = -1;
	while (ft_pf_isflag(parsed[++i]))
		lst->flags[i] = parsed[i];
	lst->flags[i] = 0;
	return (parsed + i);
}

char	ft_pf_assignlst(char *parsed, t_pf_lst *lst, va_list ap)
{
	parsed = ft_pf_assignflag(parsed, lst);
	parsed = ft_pf_assignwidth(parsed, lst, ap);
	parsed = ft_pf_assignprecision(parsed, lst, ap);
	if (lst->p_flag[0] != '.' && lst->p_value == 0)
		lst->p_value = -1;
	ft_pf_assignconverter(parsed, lst);
	if (ft_pf_istype(*parsed))
		lst->type = *parsed;
	else
		return (PARSE_ERROR);
	return (SUCCESS);
}
