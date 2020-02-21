/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:45:21 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/29 21:45:27 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

void	put_help(t_readline *r)
{
	ft_cleanstr(r->index + r->len_hint, r);
	ft_putstr_fd(GRN, 2);
	ft_putstr_fd("(reverse-i-search)`", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(BLU, 2);
	ft_putstr_fd(r->buff, 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(GRN, 2);
	ft_putstr_fd("': ", 2);
	ft_putstr_fd(RESET, 2);
}

void	ft_print_start(t_readline *p, t_readline *r)
{
	ft_start_read(r);
	ft_cleanstr(p->index + p->len_hint, p);
	ft_putstr_fd(GRN, 2);
	ft_putstr_fd("(reverse-i-search)`':", 2);
	ft_putstr_fd(RESET, 2);
	write(2, "\b\b", 2);
	r->len_hint = (int)ft_strlen("(reverse-i-search)`");
}

void	ft_return(t_readline *p, t_readline *r, char *tmp)
{
	if (tmp && tmp[0] != '\0')
	{
		free(p->buff);
		p->buff_size = 8 + (int)ft_strlen(tmp);
		p->buff = ft_strnew(p->buff_size);
		ft_strcpy(p->buff, tmp);
		p->index = (int)ft_strlen(tmp);
		p->len = (int)ft_strlen(tmp);
		free(tmp);
	}
	ft_cleanstr(r->index + r->len_hint, r);
}

void	ft_add_his_ch(t_readline *r, char c)
{
	if (r->len == r->buff_size)
		ft_realloc_buff(r);
	if (r->sum_read == 127)
	{
		if (r->index > 0)
		{
			r->buff[--r->index] = 0;
			write(2, "\b", 1);
		}
	}
	else
	{
		r->buff[r->index++] = c;
		r->len++;
	}
}

void	find_history(t_readline *p, t_memory *q)
{
	t_readline	r;
	int			rt;
	char		buf[8];
	char		*tmp;

	ft_print_start(p, &r);
	tmp = ft_strnew(1);
	while ((rt = read(0, buf, 8)))
	{
		r.sum_read = ft_add_sumchar(buf, rt);
		if (rt <= 1 && r.sum_read >= 32 && r.sum_read <= 127)
		{
			ft_add_his_ch(&r, buf[0]);
			free(tmp);
			tmp = get_num_from_hist_cons(q, r.buff);
			put_help(&r);
			ft_putstr_fd(tmp, 2);
			ft_setcursor(0, (int)ft_strlen(tmp) + 3);
		}
		else
		{
			ft_return(p, &r, tmp);
			return ;
		}
	}
}
