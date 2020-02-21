/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_bax_and_hist_change.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:52:35 by mbrella           #+#    #+#             */
/*   Updated: 2020/02/01 17:52:37 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

int				do_zam_bax_and_hist_full(t_lextoken *h)
{
	t_dop_str	*tmp;

	if (!h)
		return (-1);
	if (!(tmp = ft_memalloc(sizeof(t_dop_str))))
		ft_error_q(2);
	while (h != NULL)
	{
		tmp->c_b = 0;
		tmp->i_b = -1;
		tmp->str_b = h->line;
		if (h->inhibitor_lvl != 2)
		{
			h->line = do_zamena_sp(h->line);
			h->line = do_zam_str_bax(h->line, tmp);
			h->line = do_obr_zamena_bax(h->line);
		}
		h = h->next;
	}
	ft_kill_str_dop_lex(tmp, NULL);
	return (0);
}
