/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:36:14 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 13:06:10 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*a;
	size_t		i;

	i = 0;
	a = (const char*)s;
	while (i < n)
	{
		if (*(a + i) == (char)c)
			return ((void*)(a + i));
		i++;
	}
	return (NULL);
}
