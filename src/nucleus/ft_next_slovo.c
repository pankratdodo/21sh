/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_slovo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:32:53 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:32:54 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_next_slovo(t_readline *p)
{
	if (p->buff[p->index] == ' ')
	{
		p->index++;
		if (ft_put_n(p->len_hint, p->index, p->len) == -1)
			tputs(tgetstr("nd", NULL), 1, ft_c);
	}
	while (p->buff[p->index] == ' ' && p->index < p->len)
	{
		p->index++;
		if (ft_put_n(p->len_hint, p->index, p->len) == -1)
			tputs(tgetstr("nd", NULL), 1, ft_c);
	}
	while (p->buff[p->index] != ' ' && p->index < p->len)
	{
		p->index++;
		if (ft_put_n(p->len_hint, p->index, p->len) == -1)
			tputs(tgetstr("nd", NULL), 1, ft_c);
	}
}
