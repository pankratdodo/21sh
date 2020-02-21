/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:13:12 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:13:15 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

int			ft_fd_do_flag(t_pipe *p, int *fd_in, char **av)
{
	int			fd;

	ft_open_flag(av[p->i], &(p->flag), &fd_in, &p->fd);
	fd = p->fd;
	if (p->flag == 1 || p->flag == 2)
		dup2(p->fd, p->st);
	else if (p->flag == 6)
	{
		dup2(p->fd, 1);
		dup2(p->fd, 2);
	}
	else if (p->flag == 4)
		*fd_in = ft_heredoc(av[p->i]);
	p = &(t_pipe){0, p->i, 1, p->fd, 0, p->j};
	return (fd);
}

int			ft_fd_flag(char **av, int *fd_in)
{
	t_pipe		p;
	int			fd;

	fd = 0;
	p = (t_pipe){0, -1, 1, 0, 0, 0};
	while (av[++(p.i)])
	{
		if (p.b == 0 && av[p.i][0] >= '0' && av[p.i][0] <= '9')
			p.st = ft_atoi(av[p.i]);
		else if ((av[p.i][0] == '>' || av[p.i][0] == '<' || av[p.i][0] == '&'))
			p.flag = ft_what_flag(av[p.i], &(p.b));
		else if (p.b == 1 && p.flag != 0)
			fd = ft_fd_do_flag(&p, fd_in, av);
	}
	return (fd);
}

void		ft_pid_0(t_exectoken *head, int p[3], char *rt, pid_t pid)
{
	if (head->left != NULL)
		ft_n_pipe(p[1], &p[2], -404, NULL);
	if (head->file_opt)
		ft_fd_flag(head->file_opt, &p[2]);
	if (ft_n_pipe(-404, &p[2], p[0], NULL) && rt != NULL)
		ft_fun_fork(rt, head->file_args, pid);
	exit(0);
}

int			ft_pipe_built(t_exectoken *head, pid_t pid, t_memory *q, int *fd_in)
{
	if (is_builtin(head->file_args[0]) && head->left == NULL)
	{
		if (pid == 0)
		{
			if (head->file_opt)
				ft_fd_flag(head->file_opt, fd_in);
			ft_whatis(head, q);
			exit(0);
		}
		else
		{
			wait(NULL);
			return (1);
		}
	}
	return (0);
}

void		ft_infinit_pipe(t_exectoken *head, t_memory *q)
{
	int			p[3];
	pid_t		pid;
	char		*rt;

	p[2] = 0;
	ft_file_create(head);
	q = NULL;
	rt = NULL;
	while (head)
	{
		if (pipe(p) == -1)
			exit(0);
		ft_whatis2(head);
		if (is_builtin(head->file_args[0]) == 0)
			rt = hash_get(head->file_args[0]);
		if ((pid = fork()) == -1)
			exit(1);
		if (ft_pipe_built(head, pid, q, &p[2]))
			break ;
		if (pid == 0)
			ft_pid_0(head, p, rt, pid);
		else
			ft_n_pipe(p[1], &p[2], p[0], &head);
	}
}
