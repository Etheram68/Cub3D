/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 21:22:33 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	t_list *elem_to_del_next;
	t_list *elem_to_del;

	if (!lst || *lst == NULL)
		return ;
	elem_to_del = (*lst)->next;
	ft_lstdelone((*lst), del);
	while (elem_to_del->next)
	{
		elem_to_del_next = elem_to_del->next;
		ft_lstdelone((elem_to_del), del);
		elem_to_del = elem_to_del_next;
	}
	del(elem_to_del->content);
	free(elem_to_del);
	*lst = NULL;
}
