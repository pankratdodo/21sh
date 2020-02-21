/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:36:10 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:36:12 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_arrows(t_readline *p)
{
	if (p->sum_read == 297)
	{
		while (p->index-- > 0)
			write(2, "\b", 1);
		p->index = 0;
	}
	else if (p->sum_read == 298)
	{
		while (++p->index <= p->len)
		{
			if (ft_put_n(p->len_hint, p->index, p->len) == -1)
				tputs(tgetstr("nd", NULL), 1, ft_c);
		}
		p->index--;
	}
	else if (p->sum_read == 190)
		ft_back_slovo(p);
	else if (p->sum_read == 188)
		ft_next_slovo(p);
}
