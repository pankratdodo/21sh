/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_leftright.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:22:19 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:22:22 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_do_leftright(t_readline *p)
{
	if (p->sum_read == 186 && p->index > 0)
	{
		write(2, "\b", 1);
		p->index--;
	}
	else if (p->sum_read == 185 && p->index < p->len)
	{
		if (ft_put_n(p->len_hint, p->index + 1, p->len) == -1)
			tputs(tgetstr("nd", NULL), 1, ft_c);
		p->index++;
	}
}
