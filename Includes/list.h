/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:53:32 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/27 13:53:33 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	struct s_list	*next;
	void			*content;
}					t_list;

t_list				*list_remove_front(t_list *list, int to_free);
int					lst_count(t_list *list);
t_list				*list_add_front(t_list *list, void *content);
t_list				*list_add_back(t_list *list, void *content);
t_list				*create_list(void *content);
void				free_list(t_list *list);

#endif
