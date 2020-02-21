/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_slovo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:29:04 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:29:06 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_back_slovo(t_readline *p)
{
	if (p->buff[p->index] == ' ')
	{
		p->index--;
		write(2, "\b", 1);
	}
	while (p->index > 0 && p->buff[p->index] == ' ')
	{
		p->index--;
		write(2, "\b", 1);
	}
	while (p->index > 0 && p->buff[p->index] != ' ')
	{
		p->index--;
		write(2, "\b", 1);
	}
	while (p->index > 0 && p->buff[p->index] == ' ')
	{
		p->index--;
		write(2, "\b", 1);
	}
	if (p->index != 0)
	{
		tputs(tgetstr("nd", NULL), 1, ft_c);
		p->index++;
	}
}
