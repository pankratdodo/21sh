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

#include "libft.h"

int			ft_nb_w_str(const char *str, const char *symbols)
{
	int		i;
	int		sym;
	int		count;

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

int			ft_ln_w(const char *str, char *symbols)
{
	int		i;

	i = 0;
	while (str[i] && !(ft_strchr(symbols, str[i])))
		i++;
	return (i);
}

char		**ft_split_with_str(char *str, char *symb)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(str) || !(res = malloc(sizeof(char*) * (ft_nb_w_str(str, symb) + 2))))
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_strchr(symb, str[i]))
			i++;
		if (str[i])
		{
			k = 0;
			if (!(res[j] = malloc(sizeof(char) * (ft_ln_w(str + i, symb) + 1))))
				return (NULL);
			while (str[i] && !(ft_strchr(symb, str[i])))
				res[j][k++] = str[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}
