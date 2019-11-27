/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:57:10 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/25 18:57:11 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

int				is_unstandart(char **args, t_shell *shell)
{
	int			res;

	res = 12;
	(!ft_strcmp(args[0], "clear")) ? system("clear") : res--;
	(!ft_strcmp(args[0], "exit")) ? exit(0) : res--;
	(!ft_strcmp(args[0], "help")) ? ft_help() : res--;
	(!ft_strcmp(args[0], "echo")) ? ft_echo(args, shell) : res--;
	(!ft_strcmp(args[0], "colour")) ? ft_colour(args) : res--;
	(!ft_strcmp(args[0], "color")) ? ft_colour(args) : res--;
	(!ft_strcmp(args[0], "prompt")) ? ft_prompt(args, shell) : res--;
	(!ft_strcmp(args[0], "env")) ? ft_env(shell) : res--;
	(!ft_strcmp(args[0], "/usr/bin/env")) ? ft_env(shell) : res--;
	(!ft_strcmp(args[0], "setenv")) ? ft_setenv(args, shell) : res--;
	(!ft_strcmp(args[0], "unsetenv")) ? ft_unsetenv(args, shell) : res--;
	(!ft_strcmp(args[0], "cd")) ? ft_cd(args, shell) : res--;
	return (res);
}

int				check_command(char **args, t_shell *shell)
{
	char		*path;
	t_list		*lst;

	lst = shell->path_lst;
	if (access(args[0], X_OK))
	{
		while (lst)
		{
			path = ft_strjoin(lst->content, args[0], 0);
			if (!access(path, X_OK))
				shell->path = lst;
			free(path);
			lst = lst->next;
		}
		return (shell->path != NULL);
	}
	else
		return (1);
}

char			**shell_to_env(t_shell *shell)
{
	char		**env;
	int			i;
	t_list		*envir;


	env = malloc(sizeof(char *) * (lst_count(shell->env_lst) + 1));
	i = 0;
	envir = shell->env_lst;
	while (shell->env_lst)
	{
		env[i] = shell->env_lst->content;
		shell->env_lst = shell->env_lst->next;
		i++;
	}
	shell->env_lst = envir;
	env[i] = NULL;
	return (env);
}

void			do_command(char *command, t_shell *shell)
{
	char		**args;
	pid_t		pid;
	char        **env;

	check_exec(command, shell);
	args = ft_split_whitespaces(command);
	signal(SIGINT, (void *) int_ignore);
	if (*args && !is_unstandart(args, shell))
	{
		if (shell->type[EXEC] && check_command(args, shell))
		{
			if (!(pid = fork()))
			{
				if (shell->path)
					args[0] = ft_strjoin(shell->path->content, args[0], 2);
				env = shell_to_env(shell);
				execve(args[0], args, env);
				ft_free_split(env, 0);
			}
		}
		else
		{
			ft_putstr("21sh: command not found: ", 0);
			ft_putstr(args[0], 1);
		}
	}
	ft_free_split(args, 0);
	shell->path = NULL;
	wait(&pid);
}
