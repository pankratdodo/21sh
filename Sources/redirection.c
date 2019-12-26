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

	if (shell->type[EXEC] && shell->path && !(pid = fork()))
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
	while (com[i + 1])
	{
		if (com[i + 1] == '|')
		{
			com = parser_pipe(shell, com);
			i = 0;
		}
		else if (com[i + 1] == '<' || com[i + 1] == '>')
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
		shell->type[EXEC] = 0;
		helper_for_com(shell, com->next->content);
		res = ft_strdup(com->content);
		do_redir_pipe(shell, com->next, sepp->next, res);
		exit(0);
	}
	if (!(pid[1] = fork()))
	{
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[1]);
		shell->type[EXEC] = 0;
		helper_for_com(shell, com->content);
		res = ft_strdup(com->next->content);
		do_redir_pipe(shell, com->next, sepp->next, res);
		exit(0);
	}
	close(pipes[0]);
	close(pipes[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}

char		*check_exec(char *com, t_shell *shell)
{
	shell->commands = NULL;
	shell->sep = NULL;
	shell->fd[0] = 0;
	shell->fd[1] = 1;
	shell->oldfd[0] = 0;
	shell->oldfd[1] = 1;
	check_helper(shell, com);
	if (shell->type[PIPE] == 0 && shell->type[REDIR] == 0)
	{
		shell->type[EXEC] = 1;
		return (com);
	}
	if (shell->type[PIPE] == 1 || shell->type[REDIR] == 1)
		do_redir_pipe(shell, shell->commands, shell->sep, NULL);
	return (NULL);
}
