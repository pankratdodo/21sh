/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:38:22 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:38:23 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_cut(t_readline *p)
{
	free(g_cp);
	g_cp = ft_strdup(p->buff);
	free(p->buff);
	ft_cleanstr(p->index, p);
	ft_start_read(p);
}
