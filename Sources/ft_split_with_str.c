/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:45:56 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/29 22:46:00 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

void		ft_free_split(char **d, int crash)
{
	int		i;

	i = 0;
	if (d)
	{
		while (d[i])
		{
			free(d[i]);
			i++;
		}
		free(d);
	}
	if (crash)
		on_crash(MALLOC_ERR);
}

int		ft_nb_words(const char *str, const char *symbols)
{
	int i;
	int sym;
	int count;

	i = 0;
	sym = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && ft_strchr(symbols, str[i]) && (sym = 1))
			i++;
		if (!ft_strchr(symbols, str[i]))
		{
			count += (sym == 1) ? 1 : 0;
			sym = 0;
			i++;
		}
	}
	return (count);
}

int		ft_ln_w(const char *str, char *symbols)
{
	int i;

	i = 0;
	while (str[i] && !(ft_strchr(symbols, str[i])))
		i++;
	return (i);
}

char	**ft_split_with_str(char *str, char *symbols)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(res = malloc(sizeof(char*) * (ft_nb_words(str, symbols) + 2))))
		on_crash(MALLOC_ERR);
	while (str[i])
	{
		while (str[i] && ft_strchr(symbols, str[i]))
			i++;
		if (str[i])
		{
			k = 0;
			if (!(res[j] = malloc(sizeof(char) * ft_ln_w(str + i, symbols) + 1)))
				on_crash(MALLOC_ERR);
			while (str[i] && !(ft_strchr(symbols, str[i])))
			{
				res[j][k] = str[i];
				i++;
				k++;
			}
			res[j][k] = '\0';
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}