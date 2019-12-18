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
# define MALLOC(var, size) if (!(var = malloc(size))) on_crash(MALLOC_ERR)

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

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
	REDIR,
	EXEC,
	ELEMENTS
};

typedef struct		s_shell
{
	char			*prompt;
	int 			fd[2];
	int				is_path_prompt;
	int 			is_user_prompt;
	t_list			*env_lst;
	t_list			*path_lst;
	t_list			*path;
	t_list			*lst_parse;
	t_list			*commands;
	t_list			*sep;
	int 			type[ELEMENTS];
}					t_shell;

void				int_ignore(int signo);

void				ft_set_path_prompt(t_shell *shell);
int					is_unstandart(char **args, t_shell *shell);
void				do_command(char *command, t_shell *shell);
char				**shell_to_env(t_shell *shell);

char				**ft_split_with_str(char *str, char *symb);
void				ft_put_prompt(char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strchr_my(const char *s, char *c);
int					ft_strcmp(const char *s11, const char *s22);
int					ft_strlen(const char *src);
char				*ft_strjoin(char const *s1, char const *s2, int to_free);
void				ft_putstr(char const *str, int new_str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_free_split(char **d, int crash);
char				*ft_strrenew(char **s_ptr, const char *new_s, int to_free);
char				*ft_strstr(const char *s1, const char *s2);
char			    *ft_itoa(int n);
int                 ft_atoi(const char *str);
int					ft_strchr_twice(const char *str, char c);
char				*ft_strdup(const char *s1);
char 				*ft_strccpy(char *str, char c);
int 				ft_strclen(char *str, char c);
char 				*ft_strcpy_len(char *str, int first, int last);
void				ft_putendl_fd(char const *s, int fd);

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

char				*check_exec(char *com, t_shell *shell, int k);
pid_t				do_exec(t_shell *shell, char **args);
int					check_command(char **args, t_shell *shell);
char				*add_last_com(char *com, t_shell *shell, int i);
char				*do_redir_pipe(t_shell *shell, t_list *com, t_list *sep, char *res);

char				*parse_redir_fd(t_shell *shell, char *com);
char				*parser_pipe(t_shell *shell, char *com);
char				*parser_redir(t_shell *shell, char *com);
char				*check_quotation(const char *str, int to_free, t_shell *shell);
int 				is_not_valid(char *str);
void				return_prompt(t_shell *shell);

#endif
