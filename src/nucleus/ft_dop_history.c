/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dop_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:52:07 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/28 16:52:08 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

void		ft_dop_history(t_memory *q, t_readline *p, int k)
{
	if (k == 1)
	{
		ft_cleanstr(p->index, p);
		free(p->buff);
		p->buff_size = 8 + (int)ft_strlen((q)->inp);
		p->buff = ft_strnew(p->buff_size);
		ft_strcpy(p->buff, (q)->inp);
		p->index = (int)ft_strlen(p->buff);
		p->len = (int)ft_strlen(p->buff);
		p->len_hint = ft_printf_helper(p->mod);
		ft_putstr_fd((q)->inp, 2);
	}
	else if (k == 2)
	{
		ft_cleanstr(p->index, p);
		free(p->buff);
		p->buff_size = 64;
		p->buff = ft_strnew(p->buff_size);
		p->index = 0;
		p->len = 0;
		p->len_hint = ft_printf_helper(p->mod);
		ft_putstr_fd(p->buff, 2);
	}
}
