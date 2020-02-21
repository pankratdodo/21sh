/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:16:14 by wstygg            #+#    #+#             */
/*   Updated: 2020/01/28 17:16:15 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_HASH	255

typedef struct		s_hash
{
	char			*key;
	char			*value;
	struct s_hash	*next;
}					t_hash;

t_hash				*g_hash[MAX_HASH];

char				*hash_get(char *key);
void				hash_init(void);
void				hash_clear(void);
void				print_hash();

char				*slash_cat(char *s1, char *s2);
void				hash_free_by_key(char *key);
void				free_hash(t_hash **hash);
t_hash				*hash_create(char *key, char *value);
unsigned char		str_to_hash(char *str);
char				*hash_error(int errno, char *key);

#endif
