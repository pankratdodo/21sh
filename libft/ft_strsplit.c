/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:03:26 by qmartina          #+#    #+#             */
/*   Updated: 2019/04/18 12:24:32 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"
#include "../inc/fshell.h"

int		isdelim1(char *a, char b)
{
	if (ispar(b))
		return (2);
	while (*a)
	{
		if (*a == b)
			return (1);
		a++;
	}
	return (0);
}

int		c_size1(char *str, char b, char *delim)
{
	int i;
	int dop;

	i = 0;
	str++;
	dop = 0;
	if (*str == b)
		return (-2);
	while (*str && *str != b)
	{
		if (isdelim1(delim, *str) == 0 || ispar(*str))
			dop++;
		i++;
		str++;
	}
	if (*str == '\0' && dop > 0)
		return (-1);
	return (i);
}

int		word_size1(char *str, char *delim)
{
	int i;

	i = 0;
	if (isdelim1(delim, *str) == 2)
		return (c_size1(str, *str, delim));
	if (isdelim1(delim, str[0]) || *str == '\0')
		return (0);
	while (*str)
	{
		if (isdelim1(delim, *str))
			return (i);
		i++;
		str++;
	}
	return (i);
}

int		count_words(char *str, char *delim)
{
	int		i;
	int		dop;

	i = 0;
	while (*str)
	{
		dop = word_size1(str, delim);
		if (dop > 0)
		{
			str += dop + (ispar(*str) ? 2 : 0);
			i++;
		}
		else if (dop == -2)
			str += 2;
		else if (dop == -1)
			return (ft_error(9, "f"));
		else
			str++;
	}
	return (i);
}

char	**ft_strsplit(char *str, char *delim)
{
	char	**mas;
	int		cn;
	int		i;
	int		cn_words;

	if ((cn_words = count_words(str, delim)) <= 0)
		return (NULL);
	i = 0;
	cn_words++;
	cn = 0;
	if (!(mas = (char **)ft_memalloc(sizeof(char **) * cn_words)))
		return (NULL);
	while (i < (cn_words - 1) && str[cn])
		if (word_size1(str + cn, delim) > 0 && str[cn])
		{
			if (!(mas[i] = (char *)ft_strsub(str, cn + (ispar(str[cn]) ? 1 : 0),
					word_size1(str + cn, delim))))
				return (NULL);
			cn += word_size1(str + cn, delim) + (ispar(str[cn]) ? 2 : 0);
			i++;
		}
		else
			cn += 1 + (ispar(str[cn]) ? 1 : 0);
	mas[i] = NULL;
	return (mas);
}
