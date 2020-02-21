/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:10:31 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:10:34 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct				s_builtins
{
	int						cd_p;
	int						link;
	int						echo_n;
	int						echo_c;
}							t_builtins;

typedef struct				s_memory
{
	char					*inp;
	struct s_memory			*back;
	struct s_memory			*next;
}							t_memory;

typedef struct				s_readline
{
	char					*buff;
	int						buff_size;
	int						index;
	int						len;
	int						len_hint;
	int						sum_read;
	int						esc;
	int						mod;
	char					**tab;
	int						tab_size;
	int						tab_i;
	int						tab_max;
	int						flag_dir;
	int						flag_left_word;
	int						i_dop;
}							t_readline;

typedef struct				s_pipe
{
	int						flag;
	int						i;
	int						st;
	int						fd;
	int						b;
	int						j;
}							t_pipe;

typedef struct				s_lextoken
{
	struct s_lextoken		*prev;
	struct s_lextoken		*next;
	int						is_near_opt;
	char					*line;
	int						operator_type;
	int						inhibitor_lvl;
}							t_lextoken;

typedef struct				s_exectoken
{
	struct s_exectoken		*left;
	struct s_exectoken		*right;
	char					**file_args;
	char					**file_opt;
}							t_exectoken;

typedef struct				s_dop_str
{
	int						f_a;
	int						dopi_a;
	t_lextoken				*dop_a;
	t_exectoken				*tmp1_a;
	int						i_b;
	char					*new_b;
	char					*tmp_b;
	char					*tmp1_b;
	int						c_b;
	char					*str_b;
	int						i_c;
	t_exectoken				*prevdot_c;
	t_exectoken				*prev_c;
	t_exectoken				*start_c;
	char					*tmp_c;
	int						dop_c;
	int						d_c;
	t_lextoken				*tail_c;
	t_lextoken				*doptail_c;
}							t_dop_str;

#endif
