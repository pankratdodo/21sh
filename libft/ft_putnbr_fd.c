/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:10:28 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 10:16:03 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int res;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = n * -1;
	}
	else
		res = n;
	if (res >= 10)
		ft_putnbr_fd(res / 10, fd);
	ft_putchar_fd(res % 10 + '0', fd);
}
