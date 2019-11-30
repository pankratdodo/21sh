/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:55:51 by wstygg            #+#    #+#             */
/*   Updated: 2019/10/25 18:55:53 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define VIOLET "\033[1;35m"
# define RESET "\033[0m"

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
#include <sqlite3.h>

# include "list.h"

enum				e_error
{
	EOF_EXIT = 0,
	MALLOC_ERR,
	GETCWD_ERR
};

enum 				e_type
{
	PIPE = 0,
	REDIR_OVER,
	REDIR,
	EXEC,
	ELEMENTS
};

typedef	struct		s_redir
{
	char 			**command;
	char 			*file;
	int 			fd;
}					t_redir;

typedef struct		s_shell
{
	char			*prompt;
	int				is_path_prompt;
	t_list			*env_lst;
	t_list			*path_lst;
	t_list			*path;
	t_list			*lst_parse;
	t_redir			*redir;
	int 			type[ELEMENTS];
}					t_shell;

void				int_ignore(int signo);

void				ft_set_path_prompt(t_shell *shell);
int					is_unstandart(char **args, t_shell *shell);
void				do_command(char *command, t_shell *shell);
char				**shell_to_env(t_shell *shell);

char				**ft_split_whitespaces(char *str);
void				ft_put_prompt(char *str);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s11, const char *s22);
int					ft_strlen(const char *src);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2, int to_free);
void				ft_putstr(char const *str, int new_str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_free_split(char **d, int crash);
char				*ft_strrenew(char **s_ptr, const char *new_s, int to_free);
char				*ft_strstr(const char *s1, const char *s2);
char				*ignore_quotation(char *str, int to_free);
char			    *ft_itoa(int n);
int                 ft_atoi(const char *str);
char				*ft_strndup(const char *s1, int n);
int					kol_args(char **str);

void				initialize_readline(void);

void				ft_help(void);
void				ft_echo(char **args, t_shell *shell);
void				ft_colour(char **a);
void				ft_prompt(char *args[], t_shell *shell);
void				ft_env(t_shell *shell);
void				ft_cd(char *args[], t_shell *shell);

void				shell_init(t_shell *shell, char *envp[]);
void				path_init(t_shell *shell);

char				*parse_env(char *str, t_shell *shell, int to_free);
void				ft_unsetenv(char **args, t_shell *shell);
void				ft_setenv(char **args, t_shell *shell);

void				*on_crash(int err);

void				ignore_spaces_helper(char ***args_p);

char				**check_exec(char *com, t_shell *shell, int k);
pid_t				do_exec(t_shell *shell, char **args);

void				parser_redir(t_shell *shell, char *com, char **args);

#endif
