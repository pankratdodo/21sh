/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:54:56 by wstygg            #+#    #+#             */
/*   Updated: 2020/01/29 15:54:57 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

t_hash				*hash_create(char *key, char *value)
{
	t_hash			*ret;

	if (!(ret = malloc(sizeof(t_hash))))
		return (NULL);
	ret->key = key;
	ret->value = value;
	ret->next = NULL;
	return (ret);
}

unsigned char		str_to_hash(char *str)
{
	unsigned char	id;
	register int	i;

	id = 0;
	i = -1;
	while (str[++i])
		id += str[i] * (i + 1);
	return (id);
}

void				hash_free_by_key(char *key)
{
	t_hash			*hash;
	t_hash			*to_free;
	const int		id = str_to_hash(key);

	if ((hash = g_hash[id]) && !ft_strcmp(hash->key, key))
	{
		g_hash[id] = hash->next;
		return (free_hash(&hash));
	}
	while (hash->next)
	{
		if (!ft_strcmp(hash->next->key, key))
		{
			to_free = hash->next;
			hash->next = hash->next->next;
			return (free_hash(&to_free));
		}
		hash = hash->next;
	}
	if (!ft_strcmp(hash->key, key))
		free_hash(&hash);
}

char				*slash_cat(char *s1, char *s2)
{
	register int	i;
	register int	j;
	char			*ret;

	if (!(ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		ret[i] = s1[i];
	ret[i++] = '/';
	while (s2[++j])
		ret[i++] = s2[j];
	ret[i] = '\0';
	return (ret);
}

void				free_hash(t_hash **hash)
{
	free((*hash)->key);
	free((*hash)->value);
	free((*hash));
	*hash = NULL;
}
