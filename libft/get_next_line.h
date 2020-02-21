/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:46:05 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/19 17:37:11 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAXINT 10000
# define BUFF_SIZE 1000
# include "stdio.h"
# include "libft.h"
# include <fcntl.h>

typedef struct	s_dop
{
	ssize_t		s;
	char		*tmp;
	char		sep;
	size_t		dopi;
}				t_dop;

int				get_next_line_with_sym(const int fd, char **line, char c);
int				get_next_line(const int fd, char **line);
int				ft_strfind_index(char *s, char c);
t_dop			*ft_cr_new_node(void);
int				ft_dopdel(t_dop *d, char **mas);

#endif
