/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:00:28 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 10:01:06 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*str;
	size_t	l;
	size_t	k;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return ((char*)s);
	l = ft_strlen(s) - 1;
	i = 0;
	k = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[l] == ' ' || s[l] == '\n' || s[l] == '\t') && l > i)
		l--;
	str = ft_strnew(l - i + 1);
	if (!str || i == l)
		return (NULL);
	while (i + k <= l)
	{
		str[k] = s[i + k];
		k++;
	}
	return (str);
}
