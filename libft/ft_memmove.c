/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:46:34 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 13:05:24 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	if (dst == NULL && dst == src)
		return (dst);
	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (s < d)
	{
		while ((int)len > 0)
		{
			len--;
			*(d + len) = *(s + len);
		}
		return (d);
	}
	while (i < len)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}
