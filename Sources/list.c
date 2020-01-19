/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:53:15 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/27 13:53:16 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/list.h"

void			free_list(t_list *list)
{
	t_list		*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_list			*list_remove_front(t_list *list, int to_free)
{
	t_list		*ret;

	if (!list)
		return (NULL);
	ret = list->next;
	if (to_free)
		free(list->content);
	free(list);
	return (ret);
}

int				lst_count(t_list *list)
{
	int			count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

t_list			*list_add_back(t_list *list, void *content)
{
	t_list		*item;
	t_list		*ret;

	if (!list)
		return (create_list(content));
	ret = list;
	while (list->next)
		list = list->next;
	if (!(item = malloc(sizeof(t_list))))
	{
		write(1, "Malloc error\n", 13);
		exit(1);
	}
	item->content = content;
	item->next = NULL;
	list->next = item;
	return (ret);
}

t_list			*create_list(void *content)
{
	t_list		*ret;

	if (!(ret = malloc(sizeof(t_list))))
	{
		write(1, "Malloc error\n", 13);
		exit(1);
	}
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
