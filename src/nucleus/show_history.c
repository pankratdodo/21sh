/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:44:37 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/28 16:44:44 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

int		show_history(t_memory *q)
{
	t_memory	*tmp;
	int			i;
	int			sum;
	t_memory	*dop;

	i = 0;
	sum = 0;
	tmp = q;
	while (tmp->back)
		tmp = tmp->back;
	dop = tmp;
	while (tmp != NULL)
	{
		sum++;
		tmp = tmp->next;
	}
	tmp = dop;
	while (tmp->next)
	{
		if (sum - i < 16)
			ft_printf("%d\t%s\n", i, tmp->inp);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
