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

char		**do_redir(t_shell *shell, char *com)
{
	int		i;
	char	**args;

	i = 0;
	shell->type[REDIR] = 1;
	if (ft_strchr(com, '&'))
		return (parse_redir_fd(shell, com));
	else
	{
		while (com[i] && com[i] != '>' && com[i] != '<')
			i++;
		if (com[i] && com[i + 1] && com[i] == '<' && com[i + 1] == '<')
			shell->redir_type[REDIR_NO_OVER_IN] = 1;
		else if (com[i] && com[i + 1] && com[i] == '>' && com[i + 1] == '>')
			shell->redir_type[REDIR_NO_OVER_OUT] = 1;
		else if (com[i] && com[i + 1] && com[i] == '<' && com[i + 1] != '<')
			shell->redir_type[REDIR_OVER_IN] = 1;
		else if (com[i] && com[i + 1] && com[i] == '>' && com[i + 1] != '>')
			shell->redir_type[REDIR_OVER_OUT] = 1;
		if (com[i])
			return (ft_split_with_str(com, " \n\t<>"));
		else
			return (NULL);
	}
}

char 		**do_pipe(t_shell *shell, char *com)
{
	char	**args;

	shell->type[PIPE] = 1;
	args = ft_split_with_str(com, " \n\t|");
	return (args);
}

char 		**check_exec(char *com, t_shell *shell, int k)
{
	char	**args;

	if (k == 0)
	{
		if (ft_strchr(com, '|'))
			return (do_pipe(shell, com));
		if (ft_strchr(com, '<') || ft_strchr(com, '>'))
			return (do_redir(shell, com));
		if (shell->type[PIPE] == 0 && shell->type[REDIR] == 0)
		{
			args = ft_split_with_str(com, " \n\t");
			shell->type[EXEC] = 1;
			return (args);
		}
	}
	else if (k == 1)
	{
		shell->type[PIPE] = 0;
		shell->type[REDIR] = 0;
		shell->type[EXEC] = 0;
	}
	return (NULL);
}