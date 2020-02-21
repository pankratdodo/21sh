/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:10:53 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:10:57 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

t_lextoken					*do_lexer(char *line);
void						ft_printf(const char *fmt, ...);
t_exectoken					*all_parse(char *cmd);
t_exectoken					*do_parser(t_lextoken *tmp);
char						*do_zam_str_hist_var(char *str1, t_memory *q);
int							get_op_type(char *operator);
t_dop_str					*cr_dop_str_par(void);
int							isoperator(char c);
int							isword(char c);
int							get_op_type(char *operator);
char						*do_zamena_sp(char *line);
int							ispar(char c);
t_exectoken					*ft_cr_new_exectoken(t_lextoken *tmp,
							t_exectoken *prev, int op_type, t_dop_str *t);
int							c_size(char *str, char b);
int							word_size(char *str);
t_lextoken					*add_token(t_lextoken *start,
							char *line, int word_type);
char						*do_obr_zamena_sp(char *line);
char						*do_zam_str_bax(char *str1, t_dop_str	*t);
void						dop_cr_new_exec(t_dop_str *t,
							t_exectoken *prev, int op_type, int type);
t_dop_str					*cr_dop_str_par1(t_lextoken *tmp1);
int							ft_error(int error, char *dopline);
int							is_cmd_delim(int i);
char						*do_zam_str_bax(char *str1, t_dop_str *t);
char						*do_zam_str_hist_var(char *str1, t_memory *q);
char						*do_obr_zamena_sp(char *line);
char						*do_zamena_sp(char *line);
char						*do_zam_str_by_str(int start,
							int end, char *str, char *zam_str);
t_lextoken					*ft_cr_new_token(char *line,
							int word_type, int op_type);
t_lextoken					*add_token(t_lextoken *start,
							char *line, int word_type);
char						*do_obr_zamena_sp(char *line);
char						*do_obr_zamena_bax(char *line);
int							ispar(char c);
int							isword(char c);
int							isoperator(char c);
int							issc(char c);
int							get_op_type(char *operator);
t_lextoken					*ft_kill_str_dop_lex(t_dop_str *t, t_lextoken *tmp);
t_exectoken					*ft_kill_str_dop_exec(t_dop_str *t,
							t_exectoken *tmpexec);
t_lextoken					*do_lexer(char *line);
int							dop_lexer2(t_dop_str *tmp, char *line);
int							dop_lexer(t_dop_str *tmp, char *line);
t_dop_str					*cr_dop_str(char **line1);
int							do_zam_bax_and_hist_full(t_lextoken *h);
char						*get_num_from_hist_cons(t_memory *t, char *name);
char						*get_num_from_hist_begin(t_memory *t, int num);
char						*get_num_from_hist_end(t_memory *t, int num);
char						*get_num_from_hist_starting(t_memory *t,
							char *name);

#endif
