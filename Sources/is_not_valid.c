#include "../Includes/sh.h"

int				ft_error(char *str, int k)
{
	int			i;

	i = -1;
	if (k == 0)
	{
		ft_putstr("21sh: parse error near `", 0);
		while (str[++i] && (str[i] == '>' || str[i] == '<' || str[i] == '&'))
			write(1, &str[i], 1);
		if (!str[i])
			ft_putstr("\\n", 0);
		ft_putstr("'", 1);
	}
	if (k == 1)
	{
		ft_putstr("21sh: input error: ", 0);
		write(1, &str[i], 1);
		ft_putstr("", 1);
	}
	return (1);
}

char			*ft_strchr_my(const char *s, char *c)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s && c)
		while (s[i])
		{
			j = 0;
			while (c[j])
			{
				if (s[i] == c[j])
					return ((char *)(s + i));
				j++;
			}
			i++;
		}
	return (NULL);
}

int				ft_redir(char *str, int k)
{
	char		**args;

	args = NULL;
	if (str[1] && (str[1] == ' ' || str[1] == '\n' || str[1] == '\t'))
		args = ft_split_with_str(str + 1, " \n\t");
	else if (str[1] && k == 0 && (str[1] == '>'
				|| str[1] == '<' || str[1] == '&'))
		return (ft_redir(str + 1, 1));
	else if (str[1] && !ft_strchr("|<>&", str[1]))
		return (0);
	else
		return (ft_error(str + 1, 0));
	if (ft_strchr("|<>&", args[0][0]))
	{
		ft_error(args[0], 0);
		ft_free_split(args, 0);
		return (1);
	}
	return (0);
}

int				ft_check_redir(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			if (!str[i + 1] || (str[i + 1] && str[i + 1] == '|'))
				return (ft_error(&str[i + 1], 1));
		if (str[i] == '>' || str[i] == '<')
			return (ft_redir(str + i, 0));
		if (str[i] == '&' && str[i - 1] != '>' && str[i - 1] != '<')
			return (ft_error(&str[i + 1], 1));
		i++;
	}
	return (0);
}

int				is_not_valid(char *str)
{
	if (ft_strchr_my(str, "|><&"))
		return (ft_check_redir(str));
	return (0);
}
