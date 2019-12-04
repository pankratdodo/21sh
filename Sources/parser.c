//
// Created by Pamelia Lettie on 30/11/2019.
//

#include "../Includes/sh.h"

char		**error_parse(char *com)
{
	int		i;

	i = 0;

	if (!com)
		ft_putstr("21sh: parse error near `\\n'", 1);
	else
	{
		ft_putstr("21sh: parse error near `", 0);
		while (com[i])
		{
			if (com[i] == '&' || com[i] == '|' || com[i] == '>' || com[i] == '<')
				write(1, &com[i], 1);
			i++;
		}
		ft_putstr("'", 1);
	}
	return (NULL);
}

char 		**parse_redir_fd(t_shell *shell, char *com)
{
	char	**args;
	int 	i;

	i = 0;
	while (com[i] && com[i] != '&')
		i++;
	if (!com[i + 1])
		return (error_parse(NULL));
	else if (com[i + 1] && (ft_strchr(com + i + 1, '&') || ft_strchr(com + i + 1, '<') || ft_strchr(com + i + 1, '>')))
		return (error_parse(com + i + 1));
	if (com[i] && i != 0 && com[i - 1] == '<')
		shell->redir_type[REDIR_FD_IN] = 1;
	else if (com[i] && i != 0 && com[i - 1] == '>')
		shell->redir_type[REDIR_FD_OUT] = 1;
	args = ft_split_with_str(com, " \n\t<>&");
	return (args);
}