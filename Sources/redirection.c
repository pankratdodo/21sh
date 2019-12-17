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

#include <zconf.h>
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

void		do_pipe(t_list *command, t_list *separ, char *res)
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
		res = ft_strdup(command->content);
		do_redir_pipe(command->next, sepp->next, res);
		exit(0);
	}
	if (!(pid[1] = fork()))
	{
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[1]);
		res = ft_strdup(command->next->content);
		do_redir_pipe(command->next, sepp->next, res);
		exit(0);
	}
	close(pipes[0]);
	close(pipes[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}

void 		do_redir(t_list *command, t_list *separ, char *res)
{
	int 	fd;

	if (!(access(command->next->content, F_OK | R_OK | W_OK)))
		fd = open(command->next->content, O_CREAT | O_APPEND | O_RDWR);
	else if (!(ft_strcmp(separ->content, "<<")) || !(ft_strcmp(separ->content, ">>")))
		fd = open(command->next->content, O_APPEND | O_RDWR);
	else
		fd = open(command->next->content, O_TRUNC | O_APPEND | O_RDWR);
	if (!(ft_strcmp(separ->content, "<<")) || !(ft_strcmp(separ->content, "<")))
		dup2(fd, 0);
	else
		dup2(fd, 1);
	close(fd);
	do_redir_pipe(command->next, separ->next, res);
}

void		do_redir_pipe(t_list *command, t_list *sep, char *res)
{
	if (sep->content)
	{
		if (!(ft_strcmp(sep->content, "|")))
			do_pipe(command, sep, res);
		else if (!(ft_strcmp(sep->content, ">>")) || !(ft_strcmp(sep->content, "<<"))
			|| !(ft_strcmp(sep->content, ">")) || !(ft_strcmp(sep->content, "<")))
			do_redir(command, sep, res);
//	else if ()
//		do_fd_redir(shell);
	}
}

void		check_exec(char *com, t_shell *shell, int k)
{
	if (k == 0)
	{
		shell->commands = NULL;
		shell->sep = NULL;
		check_helper(shell, com);
		if (shell->type[PIPE] == 0 && shell->type[REDIR] == 0)
			shell->type[EXEC] = 1;
		else
			do_redir_pipe(shell->commands, shell->sep, NULL);
	}
	else if (k == 1)
	{
		shell->type[PIPE] = 0;
		shell->type[REDIR] = 0;
		shell->type[EXEC] = 0;
	}
}
