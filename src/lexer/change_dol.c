/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:25:17 by mbrella           #+#    #+#             */
/*   Updated: 2020/01/27 13:25:18 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

char				*do_zam_str_bax(char *str1, t_dop_str *t)
{
	int			start;
	int			end;
	int			dop;

	dop = 0;
	end = 0;
	while (t->str_b[++t->i_b])
		if (t->str_b[t->i_b] == '$' && t->str_b[t->i_b - 1] != '\\')
		{
			if (t->str_b[t->i_b + 1] == '{')
				dop++;
			start = t->i_b + 1;
			while (isword(t->str_b[t->i_b]) != 0 && t->str_b[t->i_b] != '}')
				t->i_b++;
			end += t->i_b + (t->str_b[t->i_b] == '}');
			str1 = ft_strsub(t->str_b, start + (dop > 0 ? 1 : 0),
				end - (dop > 0 ? 2 : 0) - start);
			t->str_b = do_zam_str_by_str(start, end,
				t->str_b, ft_get_var(str1, g_env));
			ft_strdel(&str1);
			return (t->str_b);
		}
	ft_strdel(&str1);
	return (t->str_b);
}
