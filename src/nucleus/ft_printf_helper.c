/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:58:57 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/28 16:58:58 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

int		ft_printf_helper(int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("quote> ", 2);
		return (ft_strlen("quote> "));
	}
	else if (flag == 0)
	{
		return (ft_put_info());
	}
	else if (flag == 2)
	{
		ft_putstr_fd("heredoc> ", 2);
		return (ft_strlen("heredoc> "));
	}
	return (0);
}
