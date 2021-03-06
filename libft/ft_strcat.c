/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:00:23 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 13:11:22 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (s1[k] != '\0')
		k++;
	while (s2[i] != '\0')
	{
		s1[k] = s2[i];
		k++;
		i++;
	}
	s1[k] = '\0';
	return (s1);
}
