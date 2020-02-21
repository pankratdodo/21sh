/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_funs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:06 by mbrella           #+#    #+#             */
/*   Updated: 2020/01/27 13:45:07 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ispar(char c)
{
	return (c == 34 || c == 39);
}

int				issc(char c)
{
	if (c == '(' || c == '{')
		return (1);
	else
		return (0);
}

int				isoperator(char c)
{
	return (c == '<' || c == '&' || c == '|' || c == '>' || c == ';');
}

char			find_pair_sc(char c)
{
	if (c == '(')
		return (')');
	if (c == '{')
		return ('{');
	return (0);
}

int				isword(char c)
{
	if (ispar(c) == 1)
		return (2);
	if (issc(c) == 1)
		return (3);
	if (!isoperator(c) && c != ' ' && c != '\t' && c != '\0')
		return (1);
	return (0);
}
