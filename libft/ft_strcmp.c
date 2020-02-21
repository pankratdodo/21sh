/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:50:16 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 13:17:58 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*a1;
	unsigned char	*a2;
	int				i;

	i = 0;
	a1 = (unsigned char*)s1;
	a2 = (unsigned char*)s2;
	while (a1[i] != '\0')
	{
		if (a1[i] == a2[i])
			i++;
		else
			return (a1[i] - a2[i]);
	}
	if (a1[i] == a2[i])
		return (0);
	return (a1[i] - a2[i]);
}
