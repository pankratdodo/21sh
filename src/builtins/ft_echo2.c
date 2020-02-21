/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:05:01 by plettie           #+#    #+#             */
/*   Updated: 2020/02/06 12:05:08 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fshell.h"

char	*ft_hex(char *str)
{
	int		i;

	i = 0;
	str++;
	if (*str >= '0' && *str <= '9')
	{
		i += (*str - '0');
		str++;
	}
	else if ((*str >= 'A' && *str <= 'F') || (*str >= 'a' && *str <= 'f'))
	{
		i += (*str - 'A' + 10);
		str++;
	}
	else
		str--;
	if (*str >= '0' && *str <= '9')
		i = (i * 16) + (*str - '0');
	else if ((*str >= 'A' && *str <= 'F') || (*str >= 'a' && *str <= 'f'))
		i = (i * 16) + (*str - 'A' + 10);
	else
		str--;
	str++;
	ft_putchar(i);
	return (str);
}

char	*ft_flag_echo(char *str, t_builtins *echo)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (str[i] != 'n')
			return (str);
	}
	echo->echo_n = 1;
	return (str + i);
}

char	*distr_echo(char **str, int k, int flag, t_builtins *echo)
{
	while (str[k] && *str[k])
	{
		if (*str[k] == '\\' && (flag = 1))
			str[k] = ft_slash(str[k], echo);
		else if (*str[k] == '-' && flag == 0)
			str[k] = ft_flag_echo(str[k], echo);
		else if ((flag = 1))
		{
			*str[k] != '\"' ? ft_putchar(*str[k]) : NULL;
			str[k]++;
		}
	}
	return (str[k]);
}
