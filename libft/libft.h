/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:52:52 by qmartina          #+#    #+#             */
/*   Updated: 2019/05/02 12:19:01 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				**ft_strsplit(char *s, char *c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2,
					size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src,
					size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char*));
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
void				ft_printf(const char *fmt, ...);
int					ft_nbrlen(int n);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src,
					size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src,
					int c, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_itoa(int n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_exponentiation(int nb, int k);
void				ft_list_reverse(t_list *begin_list);
void				ft_list_clear(t_list *begin_list);
void				ft_list_foreach(t_list *begin_list, void (*f)(void *));
int					ft_sqrt(int nb);
void				ft_swap(int *a, int *b);
void				*ft_realloc(void *ptr, size_t prev_size, size_t new_size);
char				*ft_strjoinch(char const *s1, char c);
char				*ft_strjoin_cmp(char const *s1, char c);
int					ft_strcmp_start(char *s1, char *s2);
void				ft_free_str(char **arr);
int					ft_count(int base, int c);
int					ft_itoa_base(int value, int base);
char				*ft_strndup(const char *s1, int n);
char				*ft_strjoinch_i(char const *s1, char c,
					size_t k, size_t max);
char				*ft_strjointsr_i(char const *s1, size_t k, char *kkk);

#endif
