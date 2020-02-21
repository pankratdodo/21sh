/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:00:46 by qmartina          #+#    #+#             */
/*   Updated: 2019/02/13 19:26:07 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list *begin_list)
{
	t_list *list;

	if (begin_list)
	{
		while (begin_list)
		{
			list = begin_list;
			begin_list = begin_list->next;
			free(list);
		}
	}
	else
		return ;
}
