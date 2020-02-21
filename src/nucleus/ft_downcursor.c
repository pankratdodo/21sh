/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_downcursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:27:19 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:27:20 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_downcursor(t_readline *p)
{
	struct winsize	wins;
	int				i;

	if (ioctl(2, TIOCGWINSZ, &wins) == -1)
		return ;
	if ((p->len - p->index) > wins.ws_col)
	{
		i = -1;
		while (++i < wins.ws_col)
		{
			if (ft_put_n(p->len_hint, p->index + 1, p->len) == -1)
				tputs(tgetstr("nd", NULL), 1, ft_c);
			p->index++;
		}
	}
	else
	{
		while (p->index < p->len)
		{
			if (ft_put_n(p->len_hint, p->index + 1, p->len) == -1)
				tputs(tgetstr("nd", NULL), 1, ft_c);
			p->index++;
		}
	}
}
