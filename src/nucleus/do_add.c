/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:04:08 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:04:09 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_do_addstr(t_readline *p, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_do_addch(p, str[i]);
}

void	ft_do_addch(t_readline *p, char c)
{
	char	tmp;
	char	tmp2;
	int		i;

	if (++p->len == p->buff_size)
		ft_realloc_buff(p);
	i = p->index++;
	tmp = p->buff[i];
	p->buff[i++] = c;
	tmp2 = p->buff[i];
	while (i < p->len)
	{
		p->buff[i++] = tmp;
		tmp = tmp2;
		tmp2 = p->buff[i];
	}
	p->buff[i] = tmp2;
	ft_cleanstr(p->index + p->len_hint, p);
	p->len_hint = ft_printf_helper(p->mod);
	write(2, p->buff, p->len);
	ft_setcursor(p->index, p->len);
}
