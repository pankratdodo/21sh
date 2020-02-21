/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:00:39 by qmartina          #+#    #+#             */
/*   Updated: 2019/05/02 12:45:16 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!lst || !f)
	{
		free(new);
		return (NULL);
	}
	else
	{
		new = f(lst);
		if (new != NULL && lst->next != NULL)
			new->next = ft_lstmap(lst->next, f);
	}
	return (new);
}
