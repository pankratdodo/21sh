/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:10:47 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 13:15:07 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*count;
	int		i;

	if (haystack == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		i = 0;
		if (*haystack == needle[i])
		{
			count = (char*)haystack;
			while (*haystack == needle[i] && needle[i] != '\0')
			{
				haystack++;
				i++;
			}
			if (needle[i] == '\0')
				return (count);
			haystack = count;
		}
		haystack++;
	}
	return (NULL);
}
