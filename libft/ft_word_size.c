/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:26:41 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 14:26:44 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_size(char const *s, char c)
{
	unsigned int cn;

	cn = 0;
	if (!s && !c)
		return (cn);
	while (!ft_isdelim(*s, c) && *s)
	{
		s++;
		cn++;
	}
	return (cn);
}
