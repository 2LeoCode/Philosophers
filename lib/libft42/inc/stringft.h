/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:18:24 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/28 21:38:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGFT_H
# define STRINGFT_H

# include <stddef.h>
# include <stdbool.h>

# define STRING_FAILURE -1
# define STRING_SUCCESS 0

typedef struct s_string	t_string;

t_string	*string_new(size_t cap);
t_string	*string_from(const char *s);
t_string	*string_dup(const t_string *s);

size_t		string_len(const t_string *s);
size_t		string_cap(const t_string *s);
char		*string_data(t_string *s);
bool		string_empty(const t_string *s);
char		string_at(const t_string *s, unsigned int index);
char		string_front(const t_string *s, unsigned int index);
char		string_back(const t_string *s, unsigned int index);

short		string_resize(t_string **s, size_t len, char c);
short		string_realloc(t_string **s, size_t cap);
short		string_app(t_string **s, const char *src);
short		string_assign(t_string **s, const char *src);
short		string_insert(t_string **s, const char *src,
				unsigned int index);
short		string_rpl(t_string **s, const char *src, unsigned int index,
				unsigned int n);
void		string_erase(t_string *s, unsigned int index, unsigned int n);
short		string_rpl_pat(t_string **s, const char *before,
				const char *after);
void		string_clear(t_string *s);

char		*string_find(const t_string *s, const char *sequence);
char		*string_rfind(const t_string *s, const char *sequence);
char		*string_ffof(const t_string *s, const char *pattern);
char		*string_flof(const t_string *s, const char *pattern);
char		*string_ffnof(const t_string *s, const char *pattern);
char		*string_flnof(const t_string *s, const char *pattern);
t_string	*string_subst(const t_string *s, size_t start, size_t len);

char		*string_beg(t_string *s);
const char	*string_cbeg(const t_string *s);
char		*string_end(t_string *s);
const char	*string_cend(const t_string *s);

int			string_put(const t_string *s);
int			string_fput(int fd, const t_string *s);
int			string_putend(const t_string *s);
int			string_fputend(int fd, const t_string *s);

#endif
