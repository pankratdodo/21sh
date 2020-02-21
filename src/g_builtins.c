/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:09:09 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:09:16 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

int		ft_heredoc(char *tmp)
{
	int			j;
	int			f[2];
	t_readline	h;

	pipe(f);
	j = 0;
	h.mod = -100;
	ft_start_read(&h);
	set_input_mode();
	while (ft_strcmp(h.buff, tmp) != 0 && ft_strcmp(h.buff, "exit") != 0)
	{
		j != 0 ? ft_putendl_fd(h.buff, f[1]) : NULL;
		h.mod = 2;
		del_readline(&h);
		ft_start_read(&h);
		ft_read_8(&h, NULL, 2);
		write(2, "\n", 1);
		j++;
	}
	close(f[1]);
	del_readline(&h);
	reset_input_mode();
	return (f[0]);
}

int		is_builtin(char *str)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (ft_strcmp(g_builtins[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		ft_whatis2(t_exectoken *tmp)
{
	if (ft_strcmp(tmp->file_args[0], "cd") == 0)
		ft_cd(tmp->file_args);
	else if (ft_strcmp(tmp->file_args[0], "setenv") == 0)
		ft_do_export(tmp->file_args);
	else if (ft_strcmp(tmp->file_args[0], "unsetenv") == 0 &&
		tmp->file_args[1] != NULL)
		unset_var(tmp->file_args[1], &g_env);
	else
		return (0);
	return (1);
}

const char		*g_builtins[10] =
{
	"unsetenv",
	"setenv",
	"history",
	"env",
	"clear",
	"hash",
	"cd",
	"echo",
	"exit",
	NULL
};
