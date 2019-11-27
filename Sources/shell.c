/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:02:31 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/25 19:02:34 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

void			ft_set_path_prompt(t_shell *shell)
{
	char		*str;

	if (!(str = getcwd(NULL, 0)))
		on_crash(GETCWD_ERR);
	free(shell->prompt);
	shell->prompt = ft_strjoin(str, "⇢  ", 1);
	ft_put_prompt(shell->prompt);
	shell->is_path_prompt = 1;
}

void			path_init(t_shell *shell)
{
	int			i;
	char		**split;
	t_list		*lst;

	if (shell->path_lst)
		while (shell->path_lst)
			shell->path_lst = list_remove_front(shell->path_lst, 1);
	if ((split = ft_strsplit(parse_env("PATH", shell, 0), ':')))
	{
		i = -1;
		while (split[++i])
			shell->path_lst = list_add_back(shell->path_lst, split[i]);
		lst = shell->path_lst;
		while (lst)
		{
			lst->content = ft_strjoin(lst->content, "/", 1);
			lst = lst->next;
		}
		free(split);
	}
}

void			shell_init(t_shell *shell, char *envp[])
{
	int			i;
    char        *str;

	i = -1;
	shell->is_path_prompt = 0;
	shell->prompt = ft_strrenew(&shell->prompt, "⇢  ", 0);
	ft_put_prompt(shell->prompt);
	shell->env_lst = NULL;
	shell->path_lst = NULL;
	shell->path = NULL;
	while (envp[++i])
		shell->env_lst = list_add_back(shell->env_lst,
		        ft_strrenew(NULL, envp[i], 0));
	if (parse_env("SHLVL", shell, 0))
	    str = ft_itoa(ft_atoi(parse_env("SHLVL", shell, 0)) + 1);
    else
        str = ft_itoa(1);
    ft_setenv((char *[]){"setenv", "SHLVL", str, NULL}, shell);
	path_init(shell);
}
