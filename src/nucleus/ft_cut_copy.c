/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:49:33 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:49:34 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_cut_copy(t_readline *p)
{
	char	*tmp;

	if (p->sum_read == 25)
		ft_putcut(p);
	else if (p->sum_read == 23)
	{
		free(g_cp);
		g_cp = ft_strndup(p->buff, p->index);
		tmp = p->buff;
		p->buff = ft_strndup(&tmp[p->index], (p->len - p->index));
		free(tmp);
		ft_cleanstr(p->index + p->len_hint, p);
		p->index = 0;
		p->len = ft_strlen(p->buff);
		p->buff_size = p->len;
		p->len_hint = ft_printf_helper(p->mod);
		write(2, p->buff, p->len);
		ft_setcursor(0, p->len);
	}
	else if (p->sum_read == 21)
		ft_cut(p);
	else if (p->sum_read == 127 && p->index > 0)
		ft_do_delch(p);
}
