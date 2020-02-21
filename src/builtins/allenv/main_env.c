/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:57:33 by mbrella           #+#    #+#             */
/*   Updated: 2020/01/31 19:57:34 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/fshell.h"

void	ft_realloc_all(int k, char ***envl)
{
	char	**tmp;
	int		i;
	char	**env;

	i = 0;
	env = *envl;
	if (env == NULL)
		return ;
	if (!(tmp = (char **)ft_memalloc(sizeof(char *) *
			(ft_env_len(env) + k))))
		ft_error_q(1);
	while (env[i])
	{
		if (!(tmp[i] = ft_strdup(env[i])))
			ft_error_q(1);
		ft_strdel(&env[i]);
		i++;
	}
	free(*envl);
	*envl = tmp;
}

int		unset_var(char *str, char ***envl)
{
	int		i;
	char	**env;

	env = *envl;
	str = ft_strjoinch(str, '=');
	i = ft_findenv(str, env);
	if (i == -404)
		return (-1);
	else
	{
		if (ft_strequ(str, "PATH="))
			hash_clear();
		free(env[i]);
		env[i] = NULL;
		while (env[i + 1])
		{
			if (!(env[i] = ft_strdup(env[i + 1])))
				return (-1);
			free(env[i + 1]);
			env[i + 1] = NULL;
			i++;
		}
	}
	return (0);
}

int		set_new_var(char *str1, char *str2, char ***envl)
{
	char	**env;
	int		i;
	char	*tmp;

	env = *envl;
	str1 = ft_strjoinch(str1, '=');
	i = ft_findenv(str1, env);
	tmp = str1;
	if (i != -404)
	{
		i = ft_findenv(str1, env);
		ft_strdel(&env[i]);
		env[i] = ft_strjoin(str1, str2);
		ft_realloc_all(2, envl);
	}
	else
	{
		i = 0;
		while (env[i])
			i++;
		env[i] = ft_strjoin(str1, str2);
		ft_realloc_all(2, envl);
	}
	ft_strdel(&tmp);
	return (0);
}
