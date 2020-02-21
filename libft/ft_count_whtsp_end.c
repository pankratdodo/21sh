/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_whtsp_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:13:36 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/11 18:13:38 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_whtsp_end(char const *s)
{
	unsigned int cn;
	unsigned int count;

	cn = ft_strlen(s) - 1;
	count = 0;
	while ((s[cn] == '\t' || s[cn] == '\n' || s[cn] == ' ') && s[cn])
	{
		cn--;
		count++;
	}
	return (count);
}
