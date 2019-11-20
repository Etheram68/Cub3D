/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 20:40:14 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lst;

	if (!alst || !new)
		return ;
	if (*alst)
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
		new->next = NULL;
	}
	else
		*alst = new;
}
