/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:49:45 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/28 16:49:46 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

t_memory	*ft_memory(t_memory *back, char **str)
{
	t_memory	*tmp;
	t_memory	*p;

	g_his_d = 0;
	tmp = (t_memory *)malloc(sizeof(t_memory));
	if (!tmp)
		return (NULL);
	p = back->next;
	back->next = tmp;
	tmp->inp = ft_strdup(*str);
	tmp->inp = do_zam_str_hist_var(tmp->inp, back);
	ft_strdel(str);
	*str = ft_strdup(tmp->inp);
	tmp->next = p;
	tmp->back = back;
	if (p != NULL)
		p->back = tmp;
	return (tmp);
}
