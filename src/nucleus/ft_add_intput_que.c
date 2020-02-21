/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_intput_que.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:02:36 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/28 17:02:39 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

void	ft_add_intput_que(t_readline *p, t_memory *head)
{
	t_readline	q;
	int			i;

	q.mod = 1;
	ft_start_read(&q);
	if (p->len == p->buff_size)
		ft_realloc_buff(p);
	p->buff[p->index++] = '\n';
	ft_read_8(&q, head, 1);
	i = -1;
	while (q.buff[++i])
	{
		if (p->len == p->buff_size)
			ft_realloc_buff(p);
		p->buff[p->index++] = q.buff[i];
		p->len++;
	}
	del_readline(&q);
	write(2, "\n", 1);
}
