/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:40:05 by qmartina          #+#    #+#             */
/*   Updated: 2019/12/16 17:40:07 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_open_f(char *str, int *flag, int *fd)
{
	if (*flag == 1 || *flag == 6)
		*fd = open(str, O_CREAT | O_RDWR | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
				S_IROTH | S_IWOTH);
	else if (*flag == 2)
		*fd = open(str, O_CREAT | O_RDWR | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
				S_IROTH | S_IWOTH);
}

void	ft_file_create(t_exectoken *head)
{
	t_exectoken *q;
	t_pipe		p;

	q = head;
	while (q)
	{
		if (q->file_opt)
		{
			p = (t_pipe){0, -1, 1, 0, 0, 0};
			while (q->file_opt[++(p.i)])
			{
				if ((q->file_opt[p.i][0] == '>' ||
					q->file_opt[p.i][0] == '<' || q->file_opt[p.i][0] == '&'))
					p.flag = ft_what_flag(q->file_opt[p.i], &(p.b));
				else if (p.b == 1 && p.flag != 0)
				{
					ft_open_f(q->file_opt[p.i], &(p.flag), &p.fd);
					p = (t_pipe){0, p.i, 1, p.fd, 0, p.j};
				}
			}
		}
		q = q->left;
	}
}
