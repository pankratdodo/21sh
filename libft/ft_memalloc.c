/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:21:42 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/17 14:36:45 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*count;

	count = (void*)malloc(sizeof(void) * size);
	if (count == NULL)
		return (NULL);
	ft_bzero(count, size);
	return (count);
}
