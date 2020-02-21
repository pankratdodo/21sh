/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:31:38 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 14:31:42 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char *s, const char delim)
{
	char			*dops;
	unsigned int	i;
	char			dopdelim;

	dopdelim = (char)delim;
	if (!s || !delim)
		return (NULL);
	if (!(dops = (char *)malloc(ft_word_size(s, dopdelim) + 1)))
		return (NULL);
	i = 0;
	while (!ft_isdelim(*s, dopdelim) && *s)
	{
		dops[i] = *s;
		s++;
		i++;
	}
	dops[i] = '\0';
	return (dops);
}
