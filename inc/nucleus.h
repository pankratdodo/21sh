/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nucleus.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:11:14 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:11:17 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUCLEUS_H
# define NUCLEUS_H

# include "struct.h"

struct termios		saved_attributes;

void				ft_read_8(t_readline *p, t_memory *head, int mod);
void				ft_do_addch(t_readline *p, char c);
void				ft_do_addstr(t_readline *p, char *str);
int					ft_put_info(void);
int					ft_printf_helper(int flag);
int					ft_c(int c);
void				reset_input_mode(void);
void				set_input_mode(void);
void				ft_realloc_buff(t_readline *p);
void				ft_cleanstr(int i, t_readline *p);
void				ft_setcursor(int i, int max);
int					ft_add_sumchar(char *str, int rt);
int					ft_put_n(int len, int i, int max);
void				ft_do_leftright(t_readline *p);
void				ft_upcursor(t_readline *p);
void				ft_downcursor(t_readline *p);
void				ft_back_slovo(t_readline *p);
void				ft_next_slovo(t_readline *p);
void				ft_arrows(t_readline *p);
void				ft_putcut(t_readline *p);
void				ft_cut(t_readline *p);
void				ft_do_delch(t_readline *p);
void				ft_cut_copy(t_readline *p);
void				ft_do_copy(t_readline *p);
char				**ft_strsplit1(char const *s, char c);
void				ft_print_tab(t_readline *p);
void				ft_realloc_tab(t_readline *p);
int					ft_max_tab_len(t_readline *p);
void				ft_cheak_tab(t_readline *p);
char				**ft_arrnew(size_t size);
void				ft_arrdel(char **arr);
int					del_readline(t_readline *p);
int					show_history(t_memory *q);
t_memory			*ft_head_memory(void);
t_memory			*ft_memory(t_memory *back, char **str);
void				ft_dop_history(t_memory *q, t_readline *p, int k);
void				ft_putmemory(t_memory **q, t_readline *p);
void				ft_start_read(t_readline *p);
int					ft_cheak_quote(char *input);
void				ft_add_intput_que(t_readline *p, t_memory *head);
char				**ft_arrnew(size_t size);
void				ft_arrdel(char **arr);
int					del_readline(t_readline *p);
void				find_history(t_readline *p, t_memory *q);

#endif
