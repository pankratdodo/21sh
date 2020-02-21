/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:32:19 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/17 16:41:39 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start,
		size_t len)
{
	char	*tmp;

	if (!s || !(tmp = ft_memalloc(len + 1)) || (len + 1) == 0)
		return (NULL);
	tmp = ft_strncpy(tmp, (char*)s + start, len);
	return (tmp);
}
