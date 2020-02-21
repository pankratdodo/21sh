/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:21:05 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:21:07 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

void	do_count_shell_lvl(void)
{
	char	*dop;
	char	*dop1;

	if (!(dop = ft_get_var("SHLVL", g_env)))
		return ;
	dop1 = ft_itoa(ft_atoi(dop) + 1);
	set_new_var("SHLVL", dop1, &g_env);
	ft_strdel(&dop);
	ft_strdel(&dop1);
}
