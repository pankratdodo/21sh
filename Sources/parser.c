#include "../Includes/sh.h"

char		**parse_redir_fd(t_shell *shell, char *com)
{
	int		i;

	i = 0;
	while (com[i] && com[i] != '&')
		i++;
	if (com[i] && com[i] == '&' && com[i - 1] == '>')
		shell->redir_type[REDIR_FD_OUT] = 1;
	else if (com[i] && com[i] == '&' && com[i - 1] == '<')
		shell->redir_type[REDIR_FD_IN] = 1;
	return (ft_split_with_str(com, "&<>"));
}
