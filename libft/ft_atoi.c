/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:25:43 by qmartina          #+#    #+#             */
/*   Updated: 2019/05/02 13:21:09 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test(int nb)
{
	if (nb == -1)
		return (0);
	if (nb == 1)
		return (-1);
	return (404);
}

static int	ft_normitene(const char *str, int nb, int sum)
{
	while (*str == '\n' || *str == '\t' || *str == '\v' ||
			*str == '\r' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '-')
		nb = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		if (((sum * 2) / 2) != sum)
			return (ft_test(nb));
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sum * nb);
}

int			ft_atoi(const char *str)
{
	int				nb;
	int				sum;

	nb = 1;
	sum = 0;
	return (ft_normitene(str, nb, sum));
}
