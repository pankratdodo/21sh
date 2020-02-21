/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:38:56 by mbrella           #+#    #+#             */
/*   Updated: 2020/01/31 18:38:57 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

char				*get_num_from_hist_begin(t_memory *t, int num)
{
	int		i;

	i = 0;
	while (t->back != NULL)
		t = t->back;
	while (t->next != NULL)
	{
		if (i == num)
			return (ft_strdup(t->inp));
		t = t->next;
		i++;
	}
	return (NULL);
}

char				*get_num_from_hist_end(t_memory *t, int num)
{
	int		i;

	i = 0;
	num = -num;
	while (t->back != NULL)
	{
		if (i == num)
			return (ft_strdup(t->inp));
		t = t->back;
		i++;
	}
	return (NULL);
}

char				*get_num_from_hist_starting(t_memory *t, char *name)
{
	int		i;

	i = 0;
	while (t->back != NULL)
	{
		if (t->inp != NULL && ft_strstr(t->inp, name) == t->inp)
			return (ft_strdup(t->inp));
		t = t->back;
		i++;
	}
	return (NULL);
}

char				*get_num_from_hist_cons(t_memory *t, char *name)
{
	int		i;

	i = 0;
	t = t->back;
	while (t->back != NULL)
	{
		if (ft_strstr(t->inp, name) != NULL)
			return (ft_strdup(t->inp));
		t = t->back;
		i++;
	}
	return (NULL);
}
