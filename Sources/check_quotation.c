/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:57:21 by wstygg            #+#    #+#             */
/*   Updated: 2019/12/05 20:57:22 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

void		put_quote_name(char c, t_shell *shell)
{
	if (c == '`')
		shell->prompt = ft_strrenew(&shell->prompt, "bquote>  ", 1);
	else if (c == '"')
		shell->prompt = ft_strrenew(&shell->prompt, "dquote>  ", 1);
	else if (c == '\'')
		shell->prompt = ft_strrenew(&shell->prompt, "quote>  ", 1);
	ft_putstr(shell->prompt, 0);
}

char		find_first(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\'' || str[i] == '"' || str[i] == '`')
			return (str[i]);
	return (-1);
}

char		*remove_quote(char *str, char c)
{
	char	*ret;
	int		i;
	int		j;
	int		dels;

	MALLOC(ret, (ft_strlen(str) - 1));
	i = -1;
	j = -1;
	dels = 0;
	while (str[++i])
	{
		if (str[i] == c && dels < 2)
			dels++;
		else
			ret[++j] = str[i];
	}
	ret[j + 1] = '\0';
	free(str);
	return (ret);
}

int			check_count(char **str, char *c)
{
	int		res;
	int		shift;

	shift = 0;
	res = 42;
	while ((*c = find_first(*str + shift)) != -1)
	{
		res = ft_strchr_twice(*str + shift, *c);
		if (res < 2)
			return (1);
		*str = remove_quote(*str, *c);
		shift += res - 2;
	}
	return (res < 2);
}

char		*check_quotation(const char *str, int to_free, t_shell *shell)
{
	char	*ret;
	char	c;
	char	**args;
	int		flag;

	flag = 0;
	args = ft_split_with_str((char *)str, " \n\t");
	if (ft_strcmp(args[0], "echo"))
		flag = 1;
	ret = ft_strjoin(str, "", to_free != 0);
	if (check_count(&ret, &c))
	{
		put_quote_name(c, shell);
		flag == 1 ? (ret = ft_strjoin(ret, "\\n", 1)) : (ret = ft_strjoin(ret, "\n", 1));
		ret = ft_strjoin(ret, readline(""), 3);
		while (check_count(&ret, &c))
		{
			put_quote_name(c, shell);
			flag == 1 ? (ret = ft_strjoin(ret, "\\n", 1)) : (ret = ft_strjoin(ret, "\n", 1));
			ret = ft_strjoin(ret, readline(""), 3);
		}
	}
	return_prompt(shell);
	return (ret);
}
