/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:51:03 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/20 18:32:16 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

void			ft_put_prompt(char *str)
{
	static char	*put;

	if (!str)
		ft_putstr(put, 0);
	else
		put = str;
}

void			my_int(void)
{
	ft_putstr("\n", 0);
	ft_put_prompt(NULL);
}

void			int_ignore(int signo)
{
	write(1, "\n", 1);
	signal(signo, SIG_IGN);
}

int				main(int ac, char *av[], char *envp[])
{
	char		*command;
	int			c;
	t_shell		shell;
	char		**comv;

	system("clear");
	shell_init(&shell, envp);
	if (ac > 1)
	{
		ft_putendl_fd("21sh: cannot execute commands", 2);
		return (0);
	}
	while ((c = -1))
	{
		signal(SIGINT, (void*)my_int);
		initialize_readline();
		command = readline(shell.prompt);
		if (!command)
			on_crash(EOF_EXIT);
		if (!*command)
			continue ;
		add_history(command);
		comv = ft_split_with_str(command, ";");
		while (comv[++c])
			do_command(comv[c], &shell);
		//ft_free_split(comv, 0);
		free(command);
	}
}
