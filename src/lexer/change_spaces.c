/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:19:10 by mbrella           #+#    #+#             */
/*   Updated: 2020/01/25 16:19:12 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

char				*do_obr_zamena_sp(char *line)
{
	int		i;
	int		d;
	int		size;
	char	*new;

	i = 0;
	d = 0;
	size = 0;
	while (line[i++] != '\0')
		size++;
	if (!(new = ft_memalloc(size * sizeof(char) + 1)))
		ft_error_q(2);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] < 0 && line[i] != -'$')
			new[d++] = -1 * (line[i++]);
		else
			new[d++] = line[i++];
	}
	new[d] = '\0';
	ft_strdel(&line);
	return (new);
}

char				*do_zamena_sp(char *line)
{
	int		i;
	int		d;
	char	*new;

	i = 0;
	d = 0;
	if (!(new = ft_memalloc(ft_strlen(line) * sizeof(char) + 1)))
		ft_error_q(2);
	while (line[i])
	{
		if (line[i] == '\\' && line[i + 1] != '\0')
		{
			new[d] = -1 * (line[i + 1]);
			i++;
		}
		else
			new[d] = line[i];
		i++;
		d++;
	}
	new[d] = '\0';
	return (new);
}

char				*do_obr_zamena_bax(char *line)
{
	int		i;
	int		d;
	int		size;
	char	*new;

	i = 0;
	d = 0;
	size = 0;
	while (line[i++] != '\0')
		size++;
	if (!(new = ft_memalloc(size * sizeof(char) + 1)))
		ft_error_q(2);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == -('$'))
			new[d++] = -1 * (line[i++]);
		else
			new[d++] = line[i++];
	}
	new[d] = '\0';
	ft_strdel(&line);
	return (new);
}
