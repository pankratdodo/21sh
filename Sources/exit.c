/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:58:54 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/25 18:58:55 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

void		*on_crash(int err)
{
	(err == EOF_EXIT) ? ft_putstr("\n    Exit", 1) : 0;
	(err == MALLOC_ERR) ? ft_putstr("Malloc error", 1) : 0;
	(err == GETCWD_ERR) ? ft_putstr("Getcwd error", 1) : 0;
	exit(err);
}
