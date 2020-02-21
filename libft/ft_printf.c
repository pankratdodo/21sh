/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:09:57 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/02 18:10:00 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static	void	ft_white(int i)
{
	int d;

	d = 0;
	while (d < i)
	{
		write(1, " ", 1);
		d++;
	}
}

static void		ft_putstr_dop(char *str, int dop1, int dop2, char const **fmt)
{
	int i;

	i = 0;
	while (*str && i <= dop2)
	{
		i++;
		if (i >= dop1 && i <= dop2)
			ft_putchar(*str);
		str++;
	}
	*fmt += ft_nbrlen(ft_atoi(*fmt + 2)) +
			ft_nbrlen(ft_atoi(*fmt + 5)) + 2;
}

void			ft_printf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	while (*fmt)
		if (*fmt != '%')
			ft_putchar(*fmt++);
		else
		{
			if (*(fmt + 1) == 'd')
				ft_putnbr(va_arg(args, int));
			else if (*(fmt + 1) == 's')
				if (ft_isdigit(*(fmt + 2)) && ft_isdigit(*(fmt + 5)))
					ft_putstr_dop(va_arg(args, char*),
							ft_atoi(fmt + 2), ft_atoi(fmt + 5), &fmt);
				else
					ft_putstr(va_arg(args, char*));
			else if (*(fmt + 1) == 'p')
				ft_white(va_arg(args, int));
			else if (*(fmt + 1) == 'c')
				ft_putchar(va_arg(args, int));
			fmt += 2;
		}
	va_end(args);
}
