/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:51:57 by qmartina          #+#    #+#             */
/*   Updated: 2019/02/13 20:35:11 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list;

	if (begin_list)
	{
		list = begin_list;
		while (list)
		{
			(*f)(list->content);
			list = list->next;
		}
	}
	else
		return ;
}
