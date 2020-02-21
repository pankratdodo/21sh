/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_dop_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:47:13 by mbrella           #+#    #+#             */
/*   Updated: 2020/01/27 13:47:14 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

t_lextoken		*ft_kill_str_dop_lex(t_dop_str *t, t_lextoken *tmp)
{
	if (t != NULL)
		free(t);
	if (tmp != NULL)
		return (tmp);
	return (NULL);
}

t_exectoken		*ft_kill_str_dop_exec(t_dop_str *t, t_exectoken *tmpexec)
{
	if (t != NULL)
		free(t);
	if (tmpexec != NULL)
		return (tmpexec);
	return (NULL);
}
