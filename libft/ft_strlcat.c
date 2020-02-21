/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:59:59 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 13:31:58 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	dln;
	size_t	sln;

	dln = ft_strlen(dst);
	sln = ft_strlen(src);
	k = 0;
	if ((dln + 1) > size)
		return (sln + size);
	if (size > (dln + 1))
	{
		while ((dln + k) < (size - 1))
		{
			dst[dln + k] = src[k];
			k++;
		}
		dst[dln + k] = '\0';
	}
	return (dln + sln);
}
