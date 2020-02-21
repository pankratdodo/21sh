/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_delch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:47:39 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:47:40 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_do_delch(t_readline *p)
{
	int		i;

	ft_cleanstr(p->index + p->len_hint, p);
	p->index--;
	i = p->index;
	while (i < p->len)
	{
		p->buff[i] = p->buff[i + 1];
		i++;
	}
	p->buff[p->len] = 0;
	p->len--;
	p->len_hint = ft_printf_helper(p->mod);
	write(2, p->buff, p->len);
	ft_setcursor(p->index, p->len);
}
