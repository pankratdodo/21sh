/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:19:16 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 14:19:18 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s, char c)
{
	unsigned int cn;

	cn = 0;
	if (!s && !c)
		return (cn);
	while (*s)
	{
		while (ft_isdelim(*s, c) && *s)
			s++;
		if (*s != '\0')
			cn++;
		while (!(ft_isdelim(*s, c)) && *s)
			s++;
	}
	return (cn);
}
