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
	char		*com;
	pid_t		pid;

	if ((!(is_not_valid(command))) && (com = check_quotation(command, 1, shell)))
	{
		if ((com = check_exec(com, shell)))
			if (shell->type[EXEC] && (args = ft_split_with_str(com, " \n\t")))
			{
				if (!is_unstandart(args, shell))
				{
					if (check_command(args, shell))
						pid = do_exec(shell, args);
					else
					{
						ft_putstr("21sh: command not found: ", 0);
						ft_putstr(args[0], 1);
					}
					wait(&pid);
				}
				ft_free_split(args, 0);
			}
		return_all(shell);
		shell->path = NULL;
		free(com);
	}
}
