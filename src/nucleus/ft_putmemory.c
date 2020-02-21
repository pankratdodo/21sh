/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmemory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:52:54 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/28 16:52:55 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

void		ft_putmemory(t_memory **q, t_readline *p)
{
	if (*q && (*q)->back && (*q)->back->back == NULL && p->sum_read == 183)
		ft_dop_history((*q), p, 1);
	else if ((*q) && p->sum_read == 183 && (*q)->back && (*q)->back->back)
	{
		if (g_his_d != 0)
			*q = (*q)->back;
		ft_dop_history(*q, p, 1);
		if ((*q)->next == NULL)
			g_his_d = 1;
	}
	else if ((*q) && p->sum_read == 184 && (*q)->next)
	{
		if ((*q)->next == NULL)
			g_his_d = 0;
		(*q) = (*q)->next;
		ft_dop_history((*q), p, 1);
	}
	else if (p->sum_read == 184)
	{
		ft_dop_history((*q), p, 2);
		g_his_d = 0;
	}
}
