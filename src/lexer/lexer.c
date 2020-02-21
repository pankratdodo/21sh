/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:53:40 by mbrella           #+#    #+#             */
/*   Updated: 2019/12/11 18:53:42 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

t_dop_str		*cr_dop_str(char **line1)
{
	t_dop_str	*tmp;
	char		*line;

	line = *line1;
	if (line == NULL)
		return (NULL);
	if (line[0] == '\0')
		return (NULL);
	if (!(tmp = ft_memalloc(sizeof(t_dop_str))))
		ft_error_q(2);
	tmp->tmp_c = NULL;
	tmp->dop_c = 0;
	tmp->d_c = 0;
	tmp->i_c = 0;
	tmp->doptail_c = NULL;
	tmp->tail_c = NULL;
	*line1 = line;
	return (tmp);
}

int				dop_lexer2(t_dop_str *tmp, char *line)
{
	tmp->tmp_c = ft_strsub(line, tmp->i_c, word_size(line + tmp->i_c));
	if (is_cmd_delim(get_op_type(tmp->tmp_c)) == 0 && tmp->i_c != 0 &&
		isword(line[tmp->i_c - 1]) && (get_op_type(tmp->tmp_c) > 6))
		tmp->tail_c->is_near_opt = 1;
	tmp->tail_c = add_token(tmp->tail_c, tmp->tmp_c, 0);
	tmp->tail_c->is_near_opt = 1;
	if (tmp->tail_c->operator_type == 2 && tmp->tail_c->prev == NULL)
		return (ft_error(5, "\\n") == -1);
	tmp->i_c += word_size(line + tmp->i_c);
	return (0);
}

int				dop_lexer1(t_dop_str *tmp, char *line)
{
	if (word_size(line + tmp->i_c) == -2)
	{
		tmp->i_c += 2;
		return (0);
	}
	tmp->tmp_c = ft_strsub(line, tmp->i_c +
	(ispar(line[tmp->i_c]) == 1 ? 1 : 0), word_size(line + tmp->i_c));
	if (tmp->tail_c != NULL && tmp->tail_c->operator_type > 2)
		tmp->d_c = 1;
	if (!(tmp->tail_c = add_token(tmp->tail_c, tmp->tmp_c, 1)))
		return (-1);
	if (ispar(line[tmp->i_c]))
		tmp->tail_c->inhibitor_lvl = line[tmp->i_c] == '"' ? 1 : 2;
	tmp->tail_c->is_near_opt = tmp->d_c;
	tmp->i_c += word_size(line + tmp->i_c) +
				(ispar(line[tmp->i_c]) ? 2 : 0);
	tmp->d_c = 0;
	return (0);
}

int				dop_lexer(t_dop_str *tmp, char *line)
{
	if (isword(line[tmp->i_c]))
	{
		if (dop_lexer1(tmp, line) == -1)
			return (-1);
	}
	else if (isoperator(line[tmp->i_c]))
	{
		if (dop_lexer2(tmp, line) == -1)
			return (-1);
	}
	else
		tmp->i_c++;
	if (tmp->dop_c == 0 && tmp->tail_c != NULL)
	{
		tmp->doptail_c = tmp->tail_c;
		tmp->dop_c = 1;
	}
	return (0);
}

t_lextoken		*do_lexer(char *line)
{
	t_dop_str	*tmp;

	if (!(tmp = cr_dop_str(&line)))
		return (NULL);
	if (line == NULL)
		return (NULL);
	while (line[tmp->i_c] != '\0')
	{
		if (dop_lexer(tmp, line) == -1)
			return (NULL);
	}
	if (tmp->tail_c != NULL && tmp->tail_c->operator_type == 2)
		return (ft_error(5, "\\n") == -1 ? NULL : 0);
	tmp->tail_c = tmp->doptail_c;
	while (tmp->tail_c)
	{
		if (tmp->tail_c->operator_type == -1)
			return (ft_error(5, tmp->tail_c->line) == -1 ? NULL : 0);
		tmp->tail_c->line = do_obr_zamena_sp(tmp->tail_c->line);
		tmp->tail_c = tmp->tail_c->next;
	}
	return (ft_kill_str_dop_lex(tmp, tmp->doptail_c));
}
