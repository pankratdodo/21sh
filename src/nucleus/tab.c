/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:39:43 by qmartina          #+#    #+#             */
/*   Updated: 2020/01/31 18:39:45 by qmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

void	ft_add_tab(t_readline *p, char *str)
{
	if (p->tab_max == p->tab_size)
		ft_realloc_tab(p);
	p->tab[p->tab_max++] = ft_strdup(str);
}

int		is_add_str_tab(t_readline *p)
{
	int		i;
	int		k;

	k = 0;
	if (p->tab_max == 1)
		return (-100);
	while (p->tab[0] && p->tab[0][k])
	{
		i = 0;
		while (i < p->tab_max && p->tab[0][k] &&
		p->tab[i][k] && p->tab[0][k] == p->tab[i][k])
			i++;
		if (i != p->tab_max)
			return (k);
		else
			k++;
	}
	return (k);
}

void	dop_to_check_tab(t_readline *p, char **str, int *i)
{
	p->flag_dir = 1;
	p->flag_left_word = 0;
	while (p->index < p->len && isword(p->buff[p->index]) == 1)
	{
		tputs(tgetstr("nd", NULL), 1, ft_c);
		p->index++;
	}
	*i = p->index;
	while (--(*i) > 0 && isword(p->buff[*i]) == 1)
		;
	p->i_dop = *i;
	while (--(p->i_dop) > 0 && isword(p->buff[p->i_dop]) != 1)
		;
	if (p->i_dop > 0)
		p->flag_left_word = 1;
	if (*i != 0)
		(*i)++;
	*str = ft_strndup(&(p->buff[*i]), p->index - *i);
	p->tab_max = 0;
}

void	dop_to_check_tab_delete(t_readline *p,
		char **name, char **str, char **dir)
{
	ft_arrdel(p->tab);
	p->tab_size = 8;
	p->tab = ft_arrnew(p->tab_size);
	p->tab_i = 0;
	free(*name);
	free(*str);
	free(*dir);
}

void	ft_cheak_tab(t_readline *p)
{
	int				i;
	char			*str;
	char			*name;
	char			*dir;

	dop_to_check_tab(p, &str, &i);
	name = ft_name(str);
	dir = ft_directory(str, &p->flag_dir);
	if (p->flag_dir == 0 && p->flag_left_word != 1)
		ft_find_path(p, str);
	else
		ft_find_dir(dir, name, p);
	i = ft_strlen(name);
	if (i < is_add_str_tab(p))
		while (i < is_add_str_tab(p))
			ft_do_addch(p, p->tab[0][i++]);
	else if (is_add_str_tab(p) == -100)
	{
		while (p->tab[0][i])
			ft_do_addch(p, p->tab[0][i++]);
		ft_do_addch(p, ' ');
	}
	else
		ft_print_tab(p);
	dop_to_check_tab_delete(p, &name, &str, &dir);
}
