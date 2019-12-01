//
// Created by Pamelia Lettie on 30/11/2019.
//

#include "../Includes/sh.h"

char 		**parse_redir_fd(t_shell *shell, char *com)
{
	char	**args;

	args = ft_split_with_str(com, " \n\t&");
	return (args);
}