/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:01:40 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/25 19:01:41 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

int			ft_str(const char *s, char c)
{
	int		i;
	int		n;
	int		k;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		k = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			k = 1;
		}
		k ? n++ : n;
	}
	return (n);
}

char		**ft_f(const char *s, char **d, char c)
{
	int		i;
	int		n;
	int		j;
	int		k;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		k = 0;
		while (s[i] && s[i] != c)
		{
			d[n][j] = s[i];
			j++;
			i++;
			k = 1;
		}
		if (k)
			d[n][j] = '\0';
		n++;
	}
	return (d);
}

char		**ft_free_split(char **d, int crash)
{
	int		i;

	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
	if (crash)
		return (on_crash(MALLOC_ERR));
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**d;
	int		n;
	int		k;

	if (!s)
		return (NULL);
	n = ft_str(s, c);
	if (!(d = (char **)malloc(sizeof(char *) * (n + 1))))
		return (on_crash(MALLOC_ERR));
	d[n] = NULL;
	i = -1;
	j = 0;
	while (++i < n)
	{
		while (s[j] && s[j] == c)
			j++;
		k = j;
		while (s[j] && s[j] != c)
			j++;
		if (!(d[i] = (char *)malloc(sizeof(char) * (j - k + 1))))
			return (ft_free_split(d, 1));
	}
	return (ft_f(s, d, c));
}
