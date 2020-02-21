/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_with_sym.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:18:16 by mbrella           #+#    #+#             */
/*   Updated: 2020/02/01 17:18:17 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_dopfunc_with(char **mas, t_dop *d, int fd, char c)
{
	d->sep = (ft_strfind_index(mas[fd], c) == -1 ? '\0' : c);
	d->dopi = ft_strfind_index(mas[fd], d->sep);
}

int		get_next_line_with_sym(const int fd, char **line, char c)
{
	static char *mas[MAXINT];
	char		buf[BUFF_SIZE + 1];
	t_dop		*d;

	d = ft_cr_new_node();
	if (fd < 0 || !line || (!mas[fd] && !(mas[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(mas[fd], c) && (d->s = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[d->s] = '\0';
		d->tmp = mas[fd];
		mas[fd] = ft_strjoin(mas[fd], buf);
		ft_strdel(&(d->tmp));
	}
	if (d->s == -1 || ft_strlen(mas[fd]) == 0)
		return (ft_dopdel(d, &mas[fd]));
	ft_dopfunc_with(mas, d, fd, c);
	*line = ft_strsub(mas[fd], 0, d->dopi);
	ft_bzero(mas[fd], d->dopi);
	if (d->sep == c)
		mas[fd] = ft_strcpy(mas[fd], (const char*)mas[fd] + d->dopi + 1);
	else
		ft_strdel(&mas[fd]);
	free(d);
	return (!(!ft_strlen(*line) && !mas[fd]));
}
