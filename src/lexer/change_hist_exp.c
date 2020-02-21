/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_hist_exp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:12:00 by mbrella           #+#    #+#             */
/*   Updated: 2020/01/27 15:12:02 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void				zm_history_numbers(int i, char **str1,
		char type, t_memory *q)
{
	int		c;
	char	*tmp;
	char	*str;

	str = *str1;
	c = i + type;
	while (isword(str[c]) != 0 && str[c])
		c++;
	tmp = ft_strdup("\0");
	if (type == 0)
		tmp = ft_strdup(get_num_from_hist_begin(q, ft_atoi(str + i + 1)));
	if (type == 2)
		tmp = ft_strdup(get_num_from_hist_end(q, ft_atoi(str + i + 1)));
	str = do_zam_str_by_str(i, c, str, tmp);
	*str1 = str;
}

void				zm_history_name(int i, char **str1, char type, t_memory *q)
{
	int		c;
	char	*tmp;
	char	*str;

	str = *str1;
	c = i + type;
	while (isword(str[c]) != 0 && str[c])
		c++;
	tmp = ft_strdup("\0");
	if (type == 1)
		tmp = ft_strdup(get_num_from_hist_starting(q,
			ft_strsub(str + i + type, 0, c - i - 1)));
	if (type == 2)
		tmp = ft_strdup(get_num_from_hist_cons(q,
			ft_strsub(str + i + 2, 0, c - i)));
	str = do_zam_str_by_str(i, c, str, tmp);
	*str1 = str;
}

char				*do_zam_str_hist_var(char *str1, t_memory *q)
{
	int			i;

	if (str1 == NULL)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == '!')
		{
			if (str1[i + 1] == '!')
				str1 = do_zam_str_by_str(i, i + 2, str1, ft_strdup(q->inp));
			else if (ft_atoi(str1 + i + 1) > 0)
				zm_history_numbers(i, &str1, 0, q);
			else if (ft_atoi(str1 + i + 1) < 0)
				zm_history_numbers(i, &str1, 2, q);
			else if (isword(str1[i + 1]) != 0 && str1[i + 1] != '?')
				zm_history_name(i, &str1, 1, q);
			else if (str1[i + 1] == '?')
				zm_history_name(i, &str1, 2, q);
		}
		i++;
	}
	return (str1);
}
