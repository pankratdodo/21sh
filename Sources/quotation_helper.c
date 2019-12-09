#include "../Includes/sh.h"

int			ft_strchr_q(const char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

int			ft_strchr_twice(const char *str, char c)
{
	int		nb;
	int		ret;

	nb = ft_strchr_q(str, c);
	if ((ret = ft_strchr_q(str + nb + 1, c)) == -1)
		return (-1);
	return (ret + nb + 2);
}

void		return_prompt(t_shell *shell)
{
	if (shell->is_user_prompt == 1)
		ft_prompt((char *[]){"prompt", "-user", NULL}, shell);
	else if (shell->is_path_prompt == 1)
		ft_prompt((char *[]){"prompt", "-path", NULL}, shell);
	else
		shell->prompt = ft_strrenew(&shell->prompt, "⇢  ", 1);
}
