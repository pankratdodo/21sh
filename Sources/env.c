/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:57:14 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/25 18:57:16 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

void			ft_unsetenv(char **args, t_shell *shell)
{
	t_list		*lst;
	char		*str;

	lst = shell->env_lst;
	if (!args[1])
	{
		ft_putstr("using: unsetenv [name]", 1);
		return ;
	}
	str = ignore_quotation(args[1], 0);
	if (parse_env(str, shell, 0))
	{
		while (lst->next != shell->lst_parse)
			lst = lst->next;
		lst->next = shell->lst_parse->next;
		free(shell->lst_parse->content);
		free(shell->lst_parse);
		if (!ft_strcmp("PATH", args[1]))
			path_init(shell);
	}
	free(str);
}

void			ft_setenv(char **args, t_shell *shell)
{
	char		*str;
	char		*name;
	char		*value;

	if (!args[1] || !args[2])
	{
		ft_putstr("using: setenv [name] [value]", 1);
		return ;
	}
	name = ignore_quotation(args[1], 0);
	if (parse_env(name, shell, 0))
		ft_unsetenv(args, shell);
	str = ft_strjoin(name, "=", 0);
	value = ignore_quotation(args[2], 0);
	str = ft_strjoin(str, value, 3);
	shell->env_lst = list_add_back(shell->env_lst, str);
	if (!ft_strcmp("PATH", name))
		path_init(shell);
	free(name);
}

char			*parse_env(char *str, t_shell *shell, int to_free)
{
	int			len;
	t_list		*lst;

	str = ft_strjoin(str, "=", to_free);
	len = ft_strlen(str);
	lst = shell->env_lst;
	while (lst)
	{
		if (ft_strstr(lst->content, str))
		{
			free(str);
			shell->lst_parse = lst;
			return (lst->content + len);
		}
		lst = lst->next;
	}
	free(str);
	return (NULL);
}
