/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:48:50 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/31 19:48:51 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

char	*hash_error(int err, char *key)
{
	if (err == 1)
	{
		ft_printf("21sh: no such file or directory: %s\n", key);
		return (NULL);
	}
	else if (err == 2)
	{
		ft_printf("21sh: command not found: %s\n", key);
		return (NULL);
	}
	else if (err == 3)
	{
		ft_printf("21sh: permission denied: %s\n", key);
		return (NULL);
	}
	return (NULL);
}
