/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 15:17:03 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:09:03 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_elem;

	new_list = NULL;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		if (!(new_list_elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_list_elem);
		lst = lst->next;
	}
	if (!(new_list_elem = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	ft_lstadd_back(&new_list, new_list_elem);
	return (new_list);
}
