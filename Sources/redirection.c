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

void		do_redir(t_shell *shell, char *com, char **args)
{
	int		i;

	i = 0;
	shell->type[REDIR] = 1;
	parser_redir(shell, com, args);
}

char 		*norm_str(char *com)
{

}

char 		**check_exec(char *com, t_shell *shell, int k)
{
	char	**args;

	args = ft_split_whitespaces(norm_str(com));
	if (k == 0)
	{
		if (ft_strchr(com, '|'))
			shell->type[PIPE] = 1;
		if (ft_strchr(com, '<') || ft_strchr(com, '>'))
			do_redir(shell, com, args);
		if (shell->type[PIPE] == 0 && shell->type[REDIR] == 0)
			shell->type[EXEC] = 1;
	}
	else if (k == 1)
	{
		shell->type[PIPE] = 0;
		shell->type[REDIR] = 0;
		shell->type[EXEC] = 0;
	}
	return(args);
}