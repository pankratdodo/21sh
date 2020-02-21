/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:02:24 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/11 19:02:43 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strfind_index(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

t_dop	*ft_cr_new_node(void)
{
	t_dop	*tmp;

	if (!(tmp = malloc(sizeof(t_dop))))
		return (NULL);
	tmp->s = 0;
	tmp->tmp = NULL;
	tmp->sep = 0;
	tmp->dopi = 0;
	return (tmp);
}

void	ft_dopfunc(char **mas, t_dop *d, int fd)
{
	d->sep = (ft_strfind_index(mas[fd], '\n') == -1 ? '\0' : '\n');
	d->dopi = ft_strfind_index(mas[fd], d->sep);
}

int		ft_dopdel(t_dop *d, char **mas)
{
	ft_strdel(mas);
	if (d->s == -1)
	{
		free(d);
		return (-1);
	}
	else
	{
		free(d);
		return (0);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char *mas[MAXINT];
	char		buf[BUFF_SIZE + 1];
	t_dop		*d;

	d = ft_cr_new_node();
	if (fd < 0 || !line || (!mas[fd] && !(mas[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(mas[fd], '\n') && (d->s = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[d->s] = '\0';
		d->tmp = mas[fd];
		mas[fd] = ft_strjoin(mas[fd], buf);
		ft_strdel(&(d->tmp));
	}
	if (d->s == -1 || ft_strlen(mas[fd]) == 0)
		return (ft_dopdel(d, &mas[fd]));
	ft_dopfunc(mas, d, fd);
	*line = ft_strsub(mas[fd], 0, d->dopi);
	ft_bzero(mas[fd], d->dopi);
	if (d->sep == '\n')
		mas[fd] = ft_strcpy(mas[fd], (const char*)mas[fd] + d->dopi + 1);
	else
		ft_strdel(&mas[fd]);
	free(d);
	return (!(!ft_strlen(*line) && !mas[fd]));
}
