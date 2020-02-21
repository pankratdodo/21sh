/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:11:48 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:11:51 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

int			ft_what_flag(char *str, int *b)
{
	int		flag;

	flag = 0;
	ft_strcmp(str, ">") == 0 ? flag = 1 : flag;
	ft_strcmp(str, ">>") == 0 ? flag = 2 : flag;
	ft_strcmp(str, "<") == 0 ? flag = 3 : flag;
	ft_strcmp(str, "<<") == 0 ? flag = 4 : flag;
	ft_strcmp(str, ">&") == 0 ? flag = 6 : flag;
	ft_strcmp(str, "&>") == 0 ? flag = 6 : flag;
	ft_strcmp(str, "&>-") == 0 ? flag = 7 : flag;
	ft_strcmp(str, ">-") == 0 ? flag = 7 : flag;
	*b = 1;
	return (flag);
}

void		ft_open_flag(char *str, int *flag, int **ff, int *fd)
{
	if (*flag == 1 || *flag == 6)
		*fd = open(str, O_CREAT | O_RDWR | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
				S_IROTH | S_IWOTH);
	else if (*flag == 2)
		*fd = open(str, O_CREAT | O_RDWR | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
				S_IROTH | S_IWOTH);
	else if (*flag == 3)
		**ff = open(str, O_RDONLY);
	if ((*flag == 1 || *flag == 6 || *flag == 2) && *fd <= 0)
	{
		ft_putstr_fd("21sh: open fd ERROR ", 2);
		ft_putendl_fd(str, 2);
		*flag = 0;
	}
	else if (*flag == 3 && **ff <= 0)
	{
		ft_putstr_fd("21sh: open fd ERROR ", 2);
		ft_putendl_fd(str, 2);
	}
}

void		ft_fun_fork(char *path, char **arg, pid_t pid)
{
	signal(SIGINT, ft_fork_signal);
	if (pid == 0)
		execve(path, arg, g_env);
	else if (pid < 0)
	{
		free(path);
		ft_putendl_fd("Fork failed to create a new process.", 2);
		return ;
	}
	if (path)
		free(path);
}

int			ft_n_pipe(int p1, int *fd_in, int p0, t_exectoken **head)
{
	if (p0 == -404 && head == NULL)
	{
		dup2(p1, 1);
		close(p1);
	}
	else if (p1 == -404 && head == NULL)
	{
		dup2(*fd_in, 0);
		close(p0);
	}
	else if (head)
	{
		wait(NULL);
		close(p1);
		*fd_in = p0;
		*head = (*head)->left;
	}
	return (1);
}
