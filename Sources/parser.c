#include "../Includes/sh.h"

char		*parser_redir(t_shell *shell, char *com)
{
	int 	i;
	char	*first;

	i = 0;
	shell->type[REDIR] = 1;
	if (ft_strchr(com, '&'))
		return (parse_redir_fd(shell, com));
	else
	{
		while (com[i] && com[i] != '>' && com[i] != '<')
			i++;
		if ((first = ft_strcpy_len(com, 0, i)))
			shell->commands = list_add_back(shell->commands, first);
		if (com[i] && com[i + 1] && com[i] == '<' && com[i + 1] == '<')
			shell->sep = list_add_back(shell->sep, "<<");
		else if (com[i] && com[i + 1] && com[i] == '>' && com[i + 1] == '>')
			shell->sep = list_add_back(shell->sep, ">>");
		else if (com[i] && com[i + 1] && com[i] == '<' && com[i + 1] != '<')
			shell->sep = list_add_back(shell->sep, "<");
		else if (com[i] && com[i + 1] && com[i] == '>' && com[i + 1] != '>')
			shell->sep = list_add_back(shell->sep, ">");
		return (add_last_com(com, shell, i + 1));
	}
}

char		*parser_pipe(t_shell *shell, char *com)
{
	int 	i;
	char 	*first;

	i = 0;
	shell->type[PIPE] = 1;
	if ((first = ft_strccpy(com, '|')))
		shell->commands = list_add_back(shell->commands, first);
	shell->sep = list_add_back(shell->sep, "|");
	i = ft_strclen(com, '|');
	return (add_last_com(com, shell, i + 1));
}

char		*parse_redir_fd(t_shell *shell, char *com)
{
	int		i;
	char 	*first;

	i = 0;
	while (com[i] && com[i] != '&')
		i++;
	if ((first = ft_strcpy_len(com, 0, i)))
		shell->commands = list_add_back(shell->commands, first);
	if (com[i] && com[i] == '&' && com[i - 1] == '>')
		shell->sep = list_add_back(shell->sep, ">&");
	else if (com[i] && com[i] == '&' && com[i - 1] == '<')
		shell->sep = list_add_back(shell->sep, "<&");
	return (add_last_com(com, shell, i + 1));
}

char		*add_last_com(char *com, t_shell *shell, int i)
{
	int 	count;

	if (com[i] && (com[i] == '>' || com[i] == '<'))
		i++;
	count = i;
	while (com[i] && com[i] != '>' && com[i] != '|' && com[i] != '<' && com[i] != '&')
		i++;
	shell->commands = list_add_back(shell->commands, ft_strcpy_len(com, count, i));
	return (com + i);
}
