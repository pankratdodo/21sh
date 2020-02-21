/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errror_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:12:39 by qmartina          #+#    #+#             */
/*   Updated: 2019/12/19 20:12:41 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

int	ft_error(int error, char *dopline)
{
	if (error == 5)
	{
		ft_printf("parse error near: %s\n", dopline);
	}
	return (-1);
}
