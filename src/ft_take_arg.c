/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:20:40 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:20:42 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

void	exit_shell(void)
{
	ft_free_str(g_env);
	write(1, "\n", 1);
	exit(0);
}

int		ft_put_info(void)
{
	char	hostname[128];
	int		k;

	k = ft_findenv("USER=", g_env);
	gethostname(hostname, sizeof(hostname));
	ft_putstr_fd(GRN, 2);
	ft_putstr_fd("[", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(CYN, 2);
	k != -404 ? ft_putstr_fd(&g_env[k][5], 2) : ft_putstr_fd("anon", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(GRN, 2);
	ft_putstr_fd("@", 2);
	ft_putstr_fd(hostname, 2);
	ft_putstr_fd("]", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(MAG, 2);
	ft_putstr_fd("\044\076\033 ", 2);
	ft_putstr_fd(RESET, 2);
	return (ft_strlen(hostname) + 6 + (k != -404 ?
		ft_strlen(&g_env[k][5]) : 4));
}
