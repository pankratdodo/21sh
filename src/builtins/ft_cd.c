/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:10:04 by plettie           #+#    #+#             */
/*   Updated: 2020/02/13 18:11:52 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

int			ft_cd_error(char *tmp, int err, int to_free)
{
	err == 1 ? ft_printf("42sh : cd: no such file or directory: %s\n", tmp) : 0;
	err == 2 ? ft_printf("42sh: cd: %s not set\n", tmp) : 0;
	err == 3 ? ft_printf("42sh: cd: not a directory: %s\n", tmp) : 0;
	err == 4 ? ft_printf("42sh: cd: no such file or directory: %s\n", tmp) : 0;
	err == 6 ? ft_printf("42sh: cd: permission denied: %s\n", tmp) : 0;
	err == 7 ? ft_printf("cd: string not in pwd: %s\n", tmp) : 0;
	err == 9 ? ft_printf("42sh: cd: too many arguments\n") : 0;
	to_free ? free(tmp) : 0;
	return (0);
}

int			flags_cd(char *str, t_builtins *cd, int j)
{
	if (str[j] == 'P')
		cd->cd_p = 1;
	else if (str[j] != 'L')
		return (ft_cd_error(str, 1, 0));
	return (1);
}

int			change_path(char *path, t_builtins *cd)
{
	char		*tmp;
	char		*pwd_env;

	if (path)
	{
		pwd_env = NULL;
		if ((tmp = get_oldpwd(cd)) && chdir(path) == -1)
		{
			free(tmp);
			return (ft_cd_error(path, 6, 0));
		}
		if (cd->cd_p && cd->link && (pwd_env = getcwd(NULL, 0)))
			if (chdir(pwd_env) == -1)
			{
				free(tmp);
				return (ft_cd_error(pwd_env, 6, 1));
			}
		set_new_var("OLDPWD", tmp, &g_env);
		pwd_env ? set_new_var("PWD", pwd_env, &g_env) :
		set_new_var("PWD", path, &g_env);
		free(pwd_env);
		free(tmp);
		return (0);
	}
	return (0);
}

int			change_env(char *env, t_builtins *cd)
{
	char		*pwd;
	int			k;

	if ((k = ft_findenv(env, g_env)) != -404)
	{
		pwd = get_oldpwd(cd);
		if (chdir(g_env[k] + ft_strlen(env)) == -1)
		{
			free(pwd);
			return (ft_cd_error(g_env[k] + ft_strlen(env), 6, 0));
		}
		set_new_var("OLDPWD", pwd, &g_env);
		set_new_var("PWD", g_env[k] + ft_strlen(env), &g_env);
		free(pwd);
		return (0);
	}
	return (ft_cd_error(env, 2, 0));
}

int			ft_cd(char **str)
{
	t_builtins	cd;
	int			i;
	int			j;

	i = 0;
	cd.link = 0;
	cd.cd_p = 0;
	while (str[++i] && !(j = 0))
	{
		if (str[i][j] == '-' && ft_strcmp(str[i], "-"))
		{
			while (str[i][++j])
				if (!flags_cd(str[i], &cd, j))
					return (1);
		}
		else if (str[i] && str[i + 1] && !str[i + 2])
			return (ft_cd_error(str[1], 7, 0));
		else if (str[i] && str[i + 1] && str[i + 2])
			return (ft_cd_error(NULL, 9, 0));
		else
			return (do_cd(&cd, str[i]));
	}
	return (change_env("HOME=", &cd));
}
