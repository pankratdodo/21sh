/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:42:35 by qmartina          #+#    #+#             */
/*   Updated: 2019/11/04 13:42:36 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_itoa_base(int value, int base)
{
	int i;
	int k;
	int dec;
	int nb;

	i = value;
	dec = 1;
	nb = 0;
	k = 0;
	while (i /= 10)
	{
		k++;
		dec *= 10;
	}
	i = value;
	while (dec > 0)
	{
		nb += ((i / dec) % 10) * ft_count(base, k);
		k--;
		dec /= 10;
	}
	return (nb);
}
