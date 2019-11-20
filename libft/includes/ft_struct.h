/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:26:21 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:02:36 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct	s_pf_lst
{
	void	*next;
	int		len;
	char	flags[6];
	int		w;
	char	p_flag[3];
	int		p_value;
	char	type;
	char	converter[3];
}				t_pf_lst;

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

#endif
