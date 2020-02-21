/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:28:48 by qmartina          #+#    #+#             */
/*   Updated: 2019/10/29 17:28:50 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/fshell.h"

char			*ft_get_var(char *dop, char **env)
{
	int		i;
	char	*dopd;

	i = 0;
	if (env == NULL)
		return (NULL);
	dopd = ft_strjoin(dop, "=");
	while (env[i])
	{
		if (ft_strstr(env[i], dopd) == env[i])
		{
			if (!(dop = ft_strsub(env[i], ft_strlen(dopd),
					ft_strlen(env[i]) - ft_strlen(dopd))))
				return (NULL);
			ft_strdel(&dopd);
			return (dop);
		}
		i++;
	}
	ft_strdel(&dopd);
	return (NULL);
}

void			ft_do_export(char **mas)
{
	if (mas == NULL)
		ft_error(15, "an error ocured");
	else if (mas[1] == NULL)
		return ;
	else if (ft_findenv(mas[1], g_env) != -404 && mas[2] == NULL)
	{
		set_new_var(mas[1], ft_get_var(mas[1], g_env), &g_env);
	}
	else if (mas[1] && mas[2] && mas[3] == NULL)
	{
		set_new_var(mas[1], mas[2], &g_env);
	}
	else
		ft_error(15, "parse error");
}
