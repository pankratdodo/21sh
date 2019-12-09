/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:20:43 by plettie           #+#    #+#             */
/*   Updated: 2019/11/27 05:20:58 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/sh.h"

int				ft_atoi(const char *str)
{
	char		*ptr;
	int			is_neg;
	int			result;

	result = 0;
	ptr = (char *)str;
	is_neg = 0;
	while (*ptr == ' ' || *ptr == '\t' || *ptr == '\v'
			|| *ptr == '\n' || *ptr == '\f' || *ptr == '\r')
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			is_neg = 1;
		ptr++;
	}
	while (*ptr && *ptr >= '0' && *ptr <= '9')
	{
		result *= 10;
		result += *ptr - '0';
		ptr++;
	}
	if (is_neg)
		result *= -1;
	return (result);
}

char			*ft_strcpy(char *dst, const char *src)
{
	char		*ret;

	ret = dst;
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (ret);
}

static int		ft_nblen_internal(int nb)
{
	int			len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static	void	ft_putnbr_buffer(int nb, char *str, int *index)
{
	if (nb == -2147483648)
	{
		ft_strcpy(str, "-2147483648");
		*index = 11;
		return ;
	}
	if (nb < 0)
	{
		str[*index] = '-';
		nb *= -1;
		(*index)++;
	}
	if (nb >= 10)
		ft_putnbr_buffer(nb / 10, str, index);
	str[*index] = nb % 10 + '0';
	(*index)++;
}

char			*ft_itoa(int n)
{
	char		*tmp;
	int			index;

	tmp = (char *)malloc(ft_nblen_internal(n) + 1);
	if (!tmp)
		return (NULL);
	*tmp = '\0';
	index = 0;
	if (!tmp)
		return (NULL);
	ft_putnbr_buffer(n, tmp, &index);
	tmp[index] = '\0';
	return (tmp);
}
