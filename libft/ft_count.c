/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:25:58 by qmartina          #+#    #+#             */
/*   Updated: 2019/11/04 13:26:00 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(int base, int c)
{
	int i;

	i = base;
	if (c == 0)
		return (1);
	while (--c)
	{
		i *= base;
	}
	return (i);
}