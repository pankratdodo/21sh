/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:46:28 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/28 16:46:29 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

t_memory	*dop_memmory(int fd)
{
	t_memory *head;

	if (!(head = (t_memory *)malloc(sizeof(t_memory))))
		ft_error_q(2);
	head->inp = NULL;
	head->next = NULL;
	head->back = NULL;
	close(fd);
	return (head);
}

t_memory	*ft_head_memory(void)
{
	t_memory	*head;
	int			fd;
	char		*line;

	fd = open("history/hist.txt", O_RDWR);
	if (get_next_line_with_sym(fd, &line, -100) <= 0)
		return (dop_memmory(fd));
	if (!(head = (t_memory *)malloc(sizeof(t_memory))))
		ft_error_q(2);
	head->inp = ft_strdup(line);
	ft_strdel(&line);
	head->back = NULL;
	while (get_next_line_with_sym(fd, &line, -100))
	{
		if (!(head->next = (t_memory *)malloc(sizeof(t_memory))))
			ft_error_q(2);
		head->next->inp = ft_strdup(line);
		ft_strdel(&line);
		head->next->next = NULL;
		head->next->back = head;
		head = head->next;
	}
	close(fd);
	return (head);
}

int			save_history(t_memory *q)
{
	int		fd;

	fd = open("history/hist.txt", O_CREAT | O_RDWR | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
			S_IROTH | S_IWOTH);
	if (fd < 0)
		return (0);
	while (q->back != NULL)
		q = q->back;
	while (q != NULL)
	{
		write(fd, q->inp, ft_strlen(q->inp));
		ft_putchar_fd(-100, fd);
		q = q->next;
	}
	ft_putchar_fd(0, fd);
	close(fd);
	return (0);
}
