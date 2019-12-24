/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:58:21 by wstygg            #+#    #+#             */
/*   Updated: 2019/11/04 14:04:51 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

static char	*command_generator(const char *text, int state)
{
	static int	i;
	static int	len;
	char		*name;
	const char	*g_cmd[] = {
			"cd", "echo", "env", "setenv", "unsetenv", "pwd", "exit",
			"emacs", "vim", "mkdir", "ls", "rm", "rmdir", "clear",
			"locate", "touch", "man", "prompt", "less", "colour",
			"mv", "gcc", "cat", (char*)NULL
	};

	if (!state)
	{
		i = 0;
		len = ft_strlen(text);
	}
	while (g_cmd[i] && (name = (char*)g_cmd[i]))
	{
		i++;
		if (ft_strncmp(name, text, len) == 0)
			return (ft_strrenew(NULL, name, 0));
	}
	return ((char *)NULL);
}

static char	**ash_complition(const char *text, int start, int end)
{
	char **matches;

	matches = NULL;
	(void)end;
	if (start == 0)
		matches = rl_completion_matches(text, command_generator);
	return (matches);
}

void		initialize_readline(void)
{
	rl_readline_name = "21sh";
	rl_attempted_completion_function = ash_complition;
}
