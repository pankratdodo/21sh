/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:27:20 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 10:11:53 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int res;

	if (n < 0)
	{
		ft_putchar('-');
		res = n * -1;
	}
	else
		res = n;
	if (res >= 10)
		ft_putnbr(res / 10);
	ft_putchar(res % 10 + '0');
}
