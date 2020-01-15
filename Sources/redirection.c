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

void			pipe_help(t_shell *shell, t_list *com, t_list *separ, int k)
{
	t_list		*sepp;
	char		*res;

	sepp = separ;
	if (k == 0)
	{
		if (!(check_command(ft_split_with_str(com->next->content," \n\t"), shell)))
		{
			ft_putstr("21sh: command not found: ", 0);
			ft_putstr(com->next->content, 1);
		}
		res = ft_strdup(com->content);
		do_redir_pipe(shell, com->next, sepp->next, res);
	}
	else
	{
		if (!(check_command(ft_split_with_str(com->content, " \n\t"), shell)))
		{
			ft_putstr("21sh: command not found: ", 0);
			ft_putstr(com->content, 1);
		}
		res = ft_strdup(com->next->content);
		do_redir_pipe(shell, com->next, sepp->next, res);
	}
}

void		do_pipe(t_shell *shell, t_list *com, t_list *separ)
{
	int			pipes[2];
	int			pid[2];

	if (pipe(pipes) != 0)
		ft_putendl_fd("pipe error", 2);
	else if (!(pid[0] = fork()))
	{
		dup2(pipes[1], STDOUT_FILENO);
		close(pipes[0]);
		pipe_help(shell, com, separ, 0);
		exit(0);
	}
	if (!(pid[1] = fork()))
	{
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[1]);
		pipe_help(shell, com, separ, 1);
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
