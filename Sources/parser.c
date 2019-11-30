//
// Created by Pamelia Lettie on 30/11/2019.
//

#include "../Includes/sh.h"

void		parse_fd(t_shell *shell, char *com)
{

}

void		no_over_redir(char *com, t_shell *shell)
{
	if (<< || >> || <> || ><)
}

void		over_redir(char *com, t_shell *shell)
{
	split;
	shell->type[REDIR_OVER] = 1;
}

void		add_redir_com(t_shell *shell, char *com, int n, char **args)
{
	if (args[0][0] == '>' || args[0][0] == '<')
		shell->redir->command = NULL;
	else
	{

	}
}
//нужно делать сплит по строчке " \t\n|><&"
void		parser_redir(t_shell *shell, char *com, char **args)
{
	int		i;

	i = 0;
	if (ft_strchr(com, '&'))
		parse_fd(shell, com);
	else
	{
		while (com[i] && com[i] != '>' && com[i] != '<')
			i++;
		add_redir_com(shell, com, i, args);
		if (com[i] && com[i + 1] && (com[i + 1] == '<' || com[i + 1] == '>'))
			no_over_redir(com + i, shell);
		else if (com[i] && com[i + 1])
			over_redir(com + i, shell);
		else
			ft_putstr("21sh: parse error near `\n'", 1);
	}
}