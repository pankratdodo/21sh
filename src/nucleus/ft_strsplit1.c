/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:52:05 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/27 17:52:07 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

static int	ft_words(char const *s, char c)
{
	int i;
	int nb;
	int flag;

	i = 0;
	flag = 1;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		if (flag == 1 && s[i] != c)
		{
			flag = 0;
			nb++;
		}
		i++;
	}
	return (nb);
}

static int	ft_wordln(char const *s, char c)
{
	int	ln;

	ln = 0;
	while (*s != c && *s != '\0')
	{
		ln++;
		s++;
	}
	return (ln);
}

char		**ft_strsplit1(char const *s, char c)
{
	char	**arr;
	int		i;
	int		nb;

	i = 0;
	if (!s)
		return (NULL);
	nb = ft_words(s, c);
	arr = (char**)malloc(sizeof(*arr) * nb + 1);
	if (!arr)
		return (NULL);
	while (i < nb)
	{
		while (*s == c && *s != '\0')
			s++;
		arr[i] = ft_strsub(s, 0, ft_wordln(s, c));
		if (!arr[i])
			return (NULL);
		s = s + ft_wordln(s, c);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
