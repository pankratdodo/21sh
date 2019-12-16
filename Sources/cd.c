/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:51:41 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/29 21:51:42 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

char			*create_full_path(char *path, t_shell *shell)
{
	char		*ret;

	if (!path)
		return (NULL);
	if (path[0] == '/')
		return (ft_strrenew(NULL, path, 0));
	if (path[0] == '~')
	{
		if (parse_env("HOME", shell, 0))
		{
			ret = ft_strjoin(parse_env("HOME", shell, 0), path + 1, 0);
			return (ret);
		}
		return (NULL);
	}
	if (!(ret = getcwd(NULL, 0)))
		on_crash(GETCWD_ERR);
	ret = ft_strjoin(ret, "/", 1);
	ret = ft_strjoin(ret, path, 1);
	return (ret);
}

void			change_old_pwd(t_shell *shell)
{
	char		**args;
	char		*str;

	MALLOC(args,(sizeof(char *) * 4));
	if (!(str = getcwd(NULL, 0)))
		on_crash(GETCWD_ERR);
	args[0] = "setenv";
	args[1] = "OLDPWD";
	args[2] = str;
	args[3] = NULL;
	ft_setenv(args, shell);
	free(str);
	free(args);
}

int				is_special_path(char *args[], t_shell *shell)
{
	char		*old_pwd;

	if (!args[1])
		return (1);
	if (!ft_strcmp(args[1], "-"))
	{
		if ((old_pwd = ft_strrenew(NULL, parse_env("OLDPWD", shell, 0), 0)))
		{
			ft_putstr(old_pwd, 1);
			change_old_pwd(shell);
			chdir(old_pwd);
			free(old_pwd);
		}
		else
			ft_putstr("An error occurred", 1);
		return (1);
	}
	if (!ft_strcmp(args[1], "~"))
		if (parse_env("HOME", shell, 0))
		{
			change_old_pwd(shell);
			chdir(parse_env("HOME", shell, 0));
			return (1);
		}
	return (0);
}

void			ft_cd_2(char *args[], t_shell *shell)
{
	struct stat	path_stat;
	char		*full_path;

	if (!access((full_path = create_full_path(args[1], shell)), F_OK))
	{
		stat(full_path, &path_stat);
		if (S_ISDIR(path_stat.st_mode))
		{
			change_old_pwd(shell);
			chdir(full_path);
		}
		else
		{
			ft_putstr("minishell: not a directory: ", 0);
			ft_putstr(args[1], 1);
		}
	}
	else
	{
		ft_putstr("minishell: no such file or directory: ", 0);
		ft_putstr(args[1], 1);
	}
	free(full_path);
}

void			ft_cd(char *args[], t_shell *shell)
{
	if (!args[1])
		if (parse_env("HOME", shell, 0))
		{
			change_old_pwd(shell);
			chdir(parse_env("HOME", shell, 0));
		}
	if (!is_special_path(args, shell))
		ft_cd_2(args, shell);
	if (shell->is_path_prompt)
		ft_set_path_prompt(shell);
}
