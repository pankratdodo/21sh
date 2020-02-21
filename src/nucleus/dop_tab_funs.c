/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_tab_funs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:36:44 by mbrella           #+#    #+#             */
/*   Updated: 2020/01/31 19:36:46 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_find_dir(char *dir, char *name, t_readline *p)
{
	DIR				*mydir;
	struct dirent	*myfile;

	mydir = opendir(dir);
	if (mydir != NULL)
	{
		while ((myfile = readdir(mydir)) != 0)
		{
			if (is_cmp(name, myfile->d_name) && myfile->d_name[0] != '.')
				ft_add_tab(p, myfile->d_name);
		}
		closedir(mydir);
	}
}

void	ft_find_path(t_readline *p, char *name)
{
	char	**path;
	int		i;
	char	*tmp;

	if (!*name)
	{
		return ;
	}
	tmp = ft_get_var("PATH", g_env);
	path = ft_strsplit1(tmp, ':');
	i = -1;
	while (path[++i])
		ft_find_dir(path[i], name, p);
	ft_strdel(&tmp);
	ft_arrdel(path);
}

char	*ft_directory(char *str, int *flag_dir)
{
	int		k;
	char	*tmp;
	char	*hp;
	char	*tmp1;

	k = ft_strlen(str);
	while (--k >= 0)
		if (str[k] == '/')
		{
			if (str[0] == '~')
			{
				if (!(hp = ft_get_var("HOME", g_env)))
					ft_error_q(5);
				tmp = ft_strndup(&str[1], k - 1);
				tmp1 = ft_strjoin(hp, tmp);
				free(hp);
				ft_strdel(&tmp);
				return (tmp1);
			}
			else
				return (ft_strndup(str, k + 1));
		}
	*flag_dir = 0;
	return (ft_strdup("./"));
}

int		is_cmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	if (s1[0] == '\0')
		return (1);
	while (s1[++i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
	}
	if (!s2[i] && s1[i])
		return (0);
	return (1);
}

char	*ft_name(char *str)
{
	int		k;

	k = ft_strlen(str);
	while (--k >= 0 && str[k] != '/' && isword(str[k]) == 1)
		;
	return (ft_strdup(&str[k + 1]));
}
