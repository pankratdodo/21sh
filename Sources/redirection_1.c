#include "../Includes/sh.h"

void		return_all(t_shell *shell)
{
	shell->type[PIPE] = 0;
	shell->type[REDIR] = 0;
	shell->type[EXEC] = 0;
	shell->fd[0] = 0;
	shell->fd[1] = 1;
}

int			create_open(t_list *sep, char *args)
{
	if (access(args, F_OK))
		return (open(args, O_APPEND | O_RDWR | O_CREAT, 0644));
	else if (access(args, R_OK | W_OK))
	{
		ft_putendl_fd("21sh: permission denied: ", 2);
		ft_putendl_fd(args, 2);
		return (0);
	}
	else if (!(ft_strcmp(sep->content, "<<"))
			|| !(ft_strcmp(sep->content, ">>")))
		return (open(args, O_APPEND | O_RDWR));
	else
		return (open(args, O_TRUNC | O_APPEND | O_RDWR));
}

void		do_dup(t_shell *shell, int in_out, int fd)
{
	shell->oldfd[in_out] = dup(shell->fd[in_out]);
	dup2(fd, shell->fd[in_out]);
	shell->fd[in_out] = fd;
}

void		do_redir(t_shell *shell, t_list *com, t_list *separ, char *res)
{
	int		fd;
	char	**args;

	args = ft_split_with_str(com->next->content, " \n\t");
	if (!(fd = create_open(separ, args[0])))
		return ;
	if (!(ft_strcmp(separ->content, "<<")) || !(ft_strcmp(separ->content, "<")))
		do_dup(shell, 0, fd);
	else
		do_dup(shell, 1, fd);
	close(fd);
	//res ? free(res) : 0;
	ft_free_split(args, 0);
	res = ft_strdup(com->content);
	do_redir_pipe(shell, com->next, separ->next, res);
	dup2(shell->oldfd[0], 0);
	dup2(shell->oldfd[1], 1);
}

char		*do_redir_pipe(t_shell *shell, t_list *com, t_list *sep, char *res)//сега когда много команд потому что он делает ферст команду которая дролжна быть ласт
{
	shell->type[EXEC] = 1;
	if (sep && sep->content)
	{
		if (!(ft_strcmp(sep->content, "|")))
			do_pipe(shell, com, sep);
		else if (!(ft_strcmp(sep->content, ">>"))
		|| !(ft_strcmp(sep->content, "<<")) || !(ft_strcmp(sep->content, ">"))
		|| !(ft_strcmp(sep->content, "<")))
			do_redir(shell, com, sep, res);
	}
	if (res)
	{
//		ft_putstr(res, 1);
		helper_for_com(shell, res);
	}
	return (res);
}
