/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pf_header.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 16:25:02 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:08:34 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PF_HEADER_H
# define FT_PF_HEADER_H

# include "ft_struct.h"

int			ft_printf(const char *format,
				...) __attribute__((format(printf,1,2)));
t_pf_lst	*ft_parse(char *format, va_list ap);
t_pf_lst	*ft_pf_newlst(void);
char		ft_pf_assignlst(char *parsed, t_pf_lst *lst, va_list ap);
void		ft_pf_assignconverter(char *parsed, t_pf_lst *lst);
char		*ft_pf_assignflag(char *parsed, t_pf_lst *lst);
char		*ft_pf_assignwidth(char *parsed, t_pf_lst *lst, va_list ap);
char		*ft_pf_assignprecision(char *parsed, t_pf_lst *lst, va_list ap);
char		*ft_pf_assigntype(char *parsed, t_pf_lst *lst);
char		ft_pf_istype(char c);
int			ft_pf_isconverter(char *str);
char		ft_pf_isprecision(char c);
char		ft_pf_isflag(char c);
int			ft_pf_print(const char *format, t_pf_lst *lst, va_list ap);
int			ft_pf_print_type(t_pf_lst *lst, va_list ap);
int			ft_pf_print_format(const char **format);
int			ft_pf_putnbr_fd(long long nb, int fd, t_pf_lst *lst);
int			ft_put_hex_fd(t_pf_lst *lst, long long nb, int fd);
int			ft_pf_putchar_fd(char d, int fd, t_pf_lst *lst);
int			ft_pf_putstr_fd(char *str, int fd, t_pf_lst *lst);
char		*ft_ptm(t_pf_lst **lst, t_pf_lst **start, char *format, va_list ap);
int			ft_pf_putaddr_fd(unsigned long nb, int fd, t_pf_lst *lst);
int			ft_pf_printf_width(t_pf_lst *lst, int ilen, char c, long long nb);

#endif
