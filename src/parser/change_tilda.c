/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_parser1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:19:33 by mbrella           #+#    #+#             */
/*   Updated: 2019/12/16 16:19:34 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void			do_zam_str_with_tilda(char **mas)
{
	int		i;
	char	*hp;
	char	*tmp;

	i = 0;
	if (!(hp = ft_get_var("HOME", g_env)))
		return ;
	while (mas[i])
	{
		if (ft_strstr(mas[i], "~/") == mas[i] ||
				ft_strcmp("~", mas[i]) == 0)
		{
			tmp = mas[i];
			mas[i] = ft_strjoin(hp, &mas[i][1]);
			ft_strdel(&tmp);
		}
		i++;
	}
	ft_strdel(&hp);
}
