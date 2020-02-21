/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:35:44 by qmartina          #+#    #+#             */
/*   Updated: 2019/11/12 15:35:47 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch_i(char const *s1, char c, size_t k, size_t max)
{
	char	*new_str;
	size_t	i;

	if (!s1 || !c)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * max + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < k)
	{
		*(new_str + i) = *(s1 + i);
		i++;
	}
	*(new_str + i) = c;
	i++;
	while (i < max && *(s1 + i - 1))
	{
		*(new_str + i) = *(s1 + i - 1);
		i++;
	}
	*(new_str + i) = '\0';
	return (new_str);
}

char	*ft_strjoin_i(char const *s1, char *c, size_t k, size_t max)
{
	char	*new_str;
	size_t	i;
	size_t	n;

	if (!s1 || !c)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (max + ft_strlen(c) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < k)
	{
		*(new_str + i) = *(s1 + i);
		i++;
	}
	n = -1;
	while (c[++n])
		*(new_str + i + n) = c[n];
	while (*(s1 + i))
	{
		*(new_str + i + n) = *(s1 + i);
		i++;
	}
	*(new_str + i + n) = '\0';
	return (new_str);
}

char	*ft_strjointsr_i(char const *s1, size_t k, char *kkk)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !kkk)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(kkk) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < k)
	{
		*(new_str + i) = *(s1 + i);
		i++;
	}
	j = -1;
	while (kkk[++j])
		*(new_str + i + j) = kkk[j];
	while (i < ft_strlen(s1) && *(s1 + i))
	{
		*(new_str + i + j) = *(s1 + i);
		i++;
	}
	*(new_str + i + j) = '\0';
	return (new_str);
}
