/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:20:53 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:20:57 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

int		ft_whatis(t_exectoken *tmp, t_memory *q)
{
	if (ft_strcmp(tmp->file_args[0], "echo") == 0)
		ft_echo(tmp->file_args);
	else if (ft_strcmp(tmp->file_args[0], "cd") == 0)
		ft_cd(tmp->file_args);
	else if (ft_strcmp(tmp->file_args[0], "setenv") == 0)
		ft_do_export(tmp->file_args);
	else if (ft_strcmp(tmp->file_args[0], "unsetenv") == 0 &&
	tmp->file_args[1] != NULL)
		unset_var(tmp->file_args[1], &g_env);
	else if (ft_strcmp(tmp->file_args[0], "history") == 0)
		show_history(q);
	else if (ft_strcmp(tmp->file_args[0], "env") == 0)
		ft_show_env(g_env);
	else if (ft_strcmp(tmp->file_args[0], "clear") == 0)
		ft_putstr_fd("\033[2J\033[H", 2);
	else if (ft_strcmp(tmp->file_args[0], "hash") == 0)
		print_hash();
	else
		return (0);
	return (1);
}

void	print_hash(void)
{
	t_hash			*hash;
	int				i;

	i = -1;
	while (++i < MAX_HASH)
	{
		if (g_hash[i] != NULL)
		{
			hash = g_hash[i];
			while (hash)
			{
				ft_putstr_fd(hash->key, 2);
				ft_putstr_fd("=", 2);
				ft_putstr_fd(hash->value, 2);
				if (hash->next)
					ft_putstr_fd("    ", 2);
				hash = hash->next;
			}
			ft_putstr_fd("\n", 2);
		}
	}
}

int		ft_main_what(t_exectoken *tmp, t_memory *q)
{
	while (tmp)
	{
		if (tmp->file_args == NULL)
			return (ft_error_args(tmp));
		if (tmp->file_args[0] == NULL)
			return (-1);
		if (ft_strcmp(tmp->file_args[0], "exit") == 0)
			return (-1);
		do_zam_str_with_tilda(tmp->file_args);
		ft_infinit_pipe(tmp, q);
		tmp = tmp->right;
	}
	return (1);
}

int		main_cycle(t_readline *p, t_memory **head, t_exectoken **start_token)
{
	t_memory	*headin;

	headin = *head;
	set_input_mode();
	ft_start_read(p);
	ft_read_8(p, headin, 0);
	write(2, "\n", 1);
	while (ft_cheak_quote(p->buff) != 1)
		ft_add_intput_que(p, headin);
	reset_input_mode();
	p->buff[0] != '\0' ? headin = ft_memory(headin, &(p->buff)) : headin;
	*start_token = all_parse(p->buff);
	if (ft_main_what(*start_token, headin) == -1)
		return (-1);
	del_readline(p);
	ft_distruct_tree(*start_token);
	*head = headin;
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	t_readline	p;
	t_memory	*head;
	t_exectoken	*start_token;

	g_his_d = 0;
	ft_bzero(&p, sizeof(t_readline));
	p.mod = 5;
	start_token = NULL;
	ft_global_env(env, argc);
	signal(SIGINT, ft_fork_signal);
	head = ft_head_memory();
	do_count_shell_lvl();
	hash_init();
	ft_put_info();
	while (argv)
		if (main_cycle(&p, &head, &start_token) == -1)
			break ;
	save_history(head);
	hash_clear();
	free(g_cp);
	ft_arrdel(g_env);
	del_readline(&p);
	reset_input_mode();
	return (ft_distruct_memory(head->next) &&
		ft_distruct_tree(start_token) ? 0 : 1);
}
