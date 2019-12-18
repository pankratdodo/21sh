/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:20:32 by plettie           #+#    #+#             */
/*   Updated: 2019/11/27 05:20:35 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

pid_t		do_exec(t_shell *shell, char **args)
{
	pid_t	pid;
	char	**env;

	if (!(pid = fork()))
	{
		if (shell->path)
			args[0] = ft_strjoin(shell->path->content, args[0], 2);
		env = shell_to_env(shell);
		execve(args[0], args, env);
		ft_free_split(env, 0);
	}
	return (pid);
}

void		check_helper(t_shell *shell, char *com)
{
	int		i;

	i = 0;
	while (com[i])
	{
		if (com[i] == '|')
		{
			com = parser_pipe(shell, com);
			i = 0;
		}
		else if (com[i] == '<' || com[i] == '>')
		{
			com = parser_redir(shell, com);
			i = 0;
		}
		else
			i++;
	}
}

void		do_pipe(t_shell *shell, t_list *com, t_list *separ, char *res)
{
	int			pipes[2];
	int			pid[2];
	t_list		*sepp;

	sepp = separ;
	if (pipe(pipes) != 0)
		ft_putendl_fd("pipe error", 2);
	else if (!(pid[0] = fork()))
	{
		dup2(pipes[1], STDOUT_FILENO);
		close(pipes[0]);
		res = ft_strdup(com->content);
		do_redir_pipe(shell, com->next, sepp->next, res);
		exit(0);
	}
	if (!(pid[1] = fork()))
	{
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[1]);
		res = ft_strdup(com->next->content);
		do_redir_pipe(shell, com->next, sepp->next, res);
		exit(0);
	}
	close(pipes[0]);
	close(pipes[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}

void 		do_redir(t_shell *shell, t_list *com, t_list *separ, char *res)
{
	int 	fd;

	if (!(access(com->next->content, F_OK | R_OK | W_OK)))
		fd = open(com->next->content, O_CREAT | O_APPEND | O_RDWR);
	else if (!(ft_strcmp(separ->content, "<<")) || !(ft_strcmp(separ->content, ">>")))
		fd = open(com->next->content, O_APPEND | O_RDWR);
	else
		fd = open(com->next->content, O_TRUNC | O_APPEND | O_RDWR);
	if (!(ft_strcmp(separ->content, "<<")) || !(ft_strcmp(separ->content, "<")))
	{
		dup2(fd, shell->fd[0]);
		shell->fd[0] = fd;
	}
	else
	{
		dup2(fd, shell->fd[1]);
		shell->fd[1] = fd;
	}
	res ? free(res) : 0;
	res = ft_strdup(com->content);
	close(fd);
	do_redir_pipe(shell, com->next, separ->next, res);
}

char		*do_redir_pipe(t_shell *shell, t_list *com, t_list *sep, char *res)
{
	if (sep->content)
	{
		if (!(ft_strcmp(sep->content, "|")))
			do_pipe(shell, com, sep, res);
		else if (!(ft_strcmp(sep->content, ">>")) || !(ft_strcmp(sep->content, "<<"))
			|| !(ft_strcmp(sep->content, ">")) || !(ft_strcmp(sep->content, "<")))
			do_redir(shell, com, sep, res);
//	else if ()
//		do_fd_redir(shell);
	}
	else
		return (NULL);
	ft_putstr("lox", 1);
	return (res);
}

char		*check_exec(char *com, t_shell *shell, int k)
{
	if (k == 0)
	{
		shell->commands = NULL;
		shell->sep = NULL;
		shell->fd[0] = 0;
		shell->fd[1] = 1;
		check_helper(shell, com);
		if (shell->type[PIPE] == 0 && shell->type[REDIR] == 0)
			shell->type[EXEC] = 1;
		else
			return (do_redir_pipe(shell, shell->commands, shell->sep, NULL));
	}
	else if (k == 1)
	{
		shell->type[PIPE] = 0;
		shell->type[REDIR] = 0;
		shell->type[EXEC] = 0;
	}
	return (NULL);
}
