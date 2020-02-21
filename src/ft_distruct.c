/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:19:33 by plettie           #+#    #+#             */
/*   Updated: 2020/02/21 22:19:36 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fshell.h"

int		ft_distruct_tree(t_exectoken *q)
{
	if (q != NULL)
	{
		ft_distruct_tree(q->left);
		ft_distruct_tree(q->right);
		ft_free_str(q->file_args);
		ft_free_str(q->file_opt);
		free(q);
	}
	return (1);
}

int		ft_distruct_memory(t_memory *head)
{
	if (head != NULL)
	{
		ft_distruct_memory(head->back);
		free(head->inp);
		free(head);
	}
	return (1);
}

int		ft_distr_lex(t_lextoken *tmp)
{
	if (tmp != NULL)
	{
		ft_distr_lex(tmp->next);
		free(tmp->line);
		free(tmp);
	}
	return (1);
}

int		ft_dist_str(char *input)
{
	ft_free_str(g_env);
	free(input);
	free(g_cp);
	return (1);
}
