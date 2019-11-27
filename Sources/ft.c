/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft's.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:51:10 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/19 17:51:11 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

char				*ft_strrenew(char **s_ptr, const char *new_str, int to_free)
{
	char			*ret;
	int				i;

	i = -1;
	if (!(ret = malloc(ft_strlen(new_str) + 1)))
		on_crash(MALLOC_ERR);
	while (new_str[++i])
		ret[i] = new_str[i];
	ret[i] = '\0';
	if (to_free && s_ptr && *s_ptr)
		free(*s_ptr);
	return (ret);
}

char				*ft_strjoin(char const *s1, char const *s2, int to_free)
{
	char			*str;
	size_t			i;
	size_t			k;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1)))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
		str[k++] = s1[i++];
	i = 0;
	while (s2[i])
		str[k++] = s2[i++];
	str[k] = '\0';
	(to_free == 1) ? free((void*)s1) : 0;
	(to_free == 2) ? free((void*)s2) : 0;
	if (to_free == 3)
	{
		free((void*)s1);
		free((void*)s2);
	}
	return (str);
}

int					ft_strcmp(const char *s11, const char *s22)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)s11;
	s2 = (unsigned char*)s22;
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
		return (s1[i] - s2[i]);
	return (0);
}

int					ft_strlen(const char *src)
{
	int				i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void				ft_putstr(char const *str, int new_str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
	if (new_str)
		write(1, "\n", 1);
}
