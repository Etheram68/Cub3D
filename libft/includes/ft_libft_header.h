/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_libft_header.h                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 14:38:17 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:05:13 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LIBFT_HEADER_H
# define FT_LIBFT_HEADER_H

# include <stdlib.h>
# include "ft_struct.h"

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *str, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(long n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void	*));
void			ft_lstclear(t_list **lst, void (*del)(void	*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				get_next_line(int fd, char **line);
char			*ft_strnew(char *src);
char			*ft_to_string(char c);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_itoa_base(long n, int base);
char			*ft_putaddr(unsigned long n);
char			*ft_strlower(char *str);
int				ft_longlonglen(long long nb);
int				ft_tohexhigh_fd(unsigned long n, int fd);
int				ft_tohexlow_fd(unsigned long n, int fd);
char			*ft_strdupnb(char *s, size_t nb);
int				ft_hexlen(unsigned long nb);
int				ft_intlen(long long nb);
void			ft_putjoinfree(char *s1, char *s2, int fd);
char			ft_have(char *s, char c);

#endif
