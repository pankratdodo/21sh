/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:20:32 by plettie           #+#    #+#             */
/*   Updated: 2019/11/27 05:20:35 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

void 		check_exec(char *com, t_shell *shell)
{
	if (ft_strchr(com, '|'))
		shell->type[PIPE] = 1;
	if (ft_strchr(com, '<') || ft_strchr(com, '>'))
		shell->type[REDIR] = 1;
	if (!shell->type[PIPE] && !shell->type[REDIR])
		shell->type[EXEC] = 1;
}