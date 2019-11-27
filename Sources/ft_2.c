/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:00:15 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/25 19:00:16 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

char				*ignore_quotation(char *str, int to_free)
{
	int				i;
	int				j;
	char			*ret;
	char			ignore;

	if (!(ret = malloc(ft_strlen(str) + 1)))
		return (on_crash(MALLOC_ERR));
	ignore = 0;
	i = 0;
	j = -1;
	while (str[++j])
	{
		if (!ignore && (str[j] == '\'' || str[j] == '\"'))
			ignore = str[j];
		if (str[j] != ignore)
			ret[i++] = str[j];
	}
	ret[i] = '\0';
	if (to_free)
		free(str);
	return (ret);
}

char				*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

char				*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (!ft_strlen(s2))
		return ((char *)s1);
	if (!ft_strncmp((char *)s1, s2, ft_strlen(s2)))
		return (((char *)s1 + i));
	return (NULL);
}
