/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:21:32 by plettie           #+#    #+#             */
/*   Updated: 2020/02/02 21:22:27 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

char		*cd_back(char *old)
{
	int			i;
	char		*new;
	int			j;

	j = -1;
	if (old)
	{
		i = ft_strlen(old);
		while (old[i] != '/')
			i--;
		if (i == 0)
		{
			free(old);
			return (ft_strdup("/"));
		}
		else if (!(new = malloc(sizeof(char *) * i + 1)))
			return (NULL);
		while (++j < i)
			new[j] = old[j];
		new[j] = '\0';
		free(old);
		return (new);
	}
	return (NULL);
}

char		*full_path_helper(char *ret, char *all, char *path)
{
	if (all && !ft_strcmp(all, ".."))
		ret = cd_back(ret);
	else if (all && ft_strcmp(all, "."))
	{
		ft_strcmp(ret, "/") ? ret = ft_strjoin_cd(ret, "/", 1) : 0;
		ret = ft_strjoin_cd(ret, all, 1);
	}
	if ((check_file(ret, IS_D)) == -1)
	{
		ft_cd_error(path, 4, 0);
		free(ret);
		return (NULL);
	}
	return (ret);
}

char		*full_path_helper_2(char *path, t_builtins *cd)
{
	char		*ret;

	if (path)
	{
		if (path[0] != '/')
			ret = get_pwd(cd);
		else
			ret = ft_strdup("/");
		return (ret);
	}
	return (NULL);
}

char		*full_path_3(char *path, char **all)
{
	int			k;

	if (!ft_strcmp(path, "-"))
		if ((k = ft_findenv("OLDPWD=", g_env)) != -404)
		{
			ft_free_str(all);
			return (ft_strdup(g_env[k] + 7));
		}
	if (!all[0])
	{
		ft_free_str(all);
		return (ft_strdup("/"));
	}
	return (NULL);
}

char		*create_full_path(char *path, t_builtins *cd)
{
	int			i;
	char		*ret;
	char		**all_path;

	i = -1;
	if (path)
	{
		all_path = ft_strsplit1(path, '/');
		if ((ret = full_path_3(path, all_path)))
			return (ret);
		ret = full_path_helper_2(path, cd);
		while (all_path[++i])
			if (!(ret = full_path_helper(ret, all_path[i], path)))
			{
				ft_free_str(all_path);
				return (NULL);
			}
		ft_free_str(all_path);
		if (!(check_file(ret, IS_E)) && !(ft_cd_error(ret, 6, 1)))
			return (NULL);
		return (ret);
	}
	return (NULL);
}
