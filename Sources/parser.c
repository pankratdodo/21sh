#include "../Includes/sh.h"

int			ft_strsearch(char *str, char *tmp, int len)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (tmp[++i])
	{
		while (str[++j] && j < len)
		{
			if (str[j] == tmp[i])
				return (1);
		}
		j = -1;
	}
	return (0);
}

void		check_first(t_shell *shell, char *com, int i)
{
	char	*first;
	int		j;

	j = 0;
	if (!(ft_strsearch(com, "|<>&", i)))
	{
		if (!(first = malloc(sizeof(char*) * i)))
			on_crash(MALLOC_ERR);
		while (j < i)
		{
			first[j] = com[j];
			j++;
		}
		first[j] = '\0';
		shell->commands = list_add_back(shell->commands, first);
	}
}

void		parser_redir(t_shell *shell, char *com, int i)
{
	int		j;

	shell->type[REDIR] = 1;
	check_first(shell, com, i);
	if (!(parse_redir_fd(shell, com, i)))
	{
		if (com[i] && com[i] == '<' && com[i + 1] == '<')
			shell->sep = list_add_back(shell->sep, "<<");
		if (com[i] && com[i] == '>' && com[i + 1] == '>')
			shell->sep = list_add_back(shell->sep, ">>");
		if (com[i] && com[i] == '<' && com[i + 1] != '<')
			shell->sep = list_add_back(shell->sep, "<");
		if (com[i] && com[i] == '>' && com[i + 1] != '>')
			shell->sep = list_add_back(shell->sep, ">");
	}
	while (com[i] && (com[i] == '>' || com[i] == '<' || com[i] == '&'))
		j = ++i;
	while (com[i] && com[i] != '<' && com[i] != '>' && com[i] != '|' && com[i] != '&')
		i++;
	shell->commands = list_add_back(shell->commands, ft_strcpy_len(com, j, i - 1));
}

void		parser_pipe(t_shell *shell, char *com, int i)
{
	int		j;

	shell->type[PIPE] = 1;
	check_first(shell, com, i);
	shell->sep = list_add_back(shell->sep, "|");
	j = ++i;
	while (com[i] && com[i] != '<' && com[i] != '>' && com[i] != '|' && com[i] != '&')
		i++;
	shell->commands = list_add_back(shell->commands, ft_strcpy_len(com, j, i - 1));
}

int			parse_redir_fd(t_shell *shell, char *com, int i)
{
	if (com[i] && com[i] == '<' && com[i + 1] == '&')
		shell->sep = list_add_back(shell->sep, "<&");
	else if (com[i] && com[i] == '>' && com[i + 1] == '&')
		shell->sep = list_add_back(shell->sep, ">&");
	else if (com[i] && com[i] == '&' && com[i + 1] == '<')
		shell->sep = list_add_back(shell->sep, "&<");
	else if (com[i] && com[i] == '&' && com[i + 1] == '>')
		shell->sep = list_add_back(shell->sep, "&>");
	else
		return (0);
	return (1);
}
