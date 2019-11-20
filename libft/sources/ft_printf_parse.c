/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_parse.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:43:12 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:32 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_pf_lst	*ft_pf_newlst(void)
{
	t_pf_lst	*new;
	int			i;

	i = 0;
	if (!(new = malloc(sizeof(t_pf_lst))))
		return (NULL);
	new->next = NULL;
	new->len = 0;
	new->w = 0;
	new->p_value = 0;
	new->type = 0;
	while (i < 6)
	{
		new->flags[i] = 0;
		i++;
	}
	return (new);
}

char		*ft_ptmdeux(t_pf_lst *lst, char *format, char *parsed, va_list ap)
{
	int i;

	i = 0;
	while (++i < lst->len + 1)
		parsed[i - 1] = format[i - 1];
	parsed[i - 1] = 0;
	ft_pf_assignlst(parsed, lst, ap);
	free(parsed);
	return (format + (lst->len));
}

char		*ft_ptm(t_pf_lst **lst, t_pf_lst **start, char *format, va_list ap)
{
	char	*parsed;
	int		i;

	i = 0;
	if (!lst[0])
	{
		*lst = ft_pf_newlst();
		*start = *lst;
	}
	else
	{
		(*lst)->next = ft_pf_newlst();
		*lst = (*lst)->next;
	}
	while (!ft_pf_istype(format[i]) && (ft_pf_isflag(format[i])
		|| ft_pf_isprecision(format[i]) || ft_isdigit(format[i])))
		i++;
	!ft_pf_istype(format[i]) ? i-- : 0;
	(*lst)->len = i + 1;
	if (!(parsed = malloc(sizeof(char) * (*lst)->len + 1)))
		return (MALLOC_ERROR);
	return (ft_ptmdeux(*lst, format, parsed, ap));
}

t_pf_lst	*ft_parse(char *format, va_list ap)
{
	t_pf_lst	*lst;
	t_pf_lst	*start;
	int			i;

	lst = NULL;
	start = NULL;
	while (*format)
	{
		i = 0;
		if (*format == '%')
		{
			if (!ft_pf_istype(format[1]) && !ft_pf_isflag(format[1])
				&& !ft_pf_isprecision(format[1]) && !ft_isdigit(format[1]))
				return (start);
			else
				format = ft_ptm(&lst, &start, format + 1, ap);
		}
		else
			format++;
	}
	return (start);
}
