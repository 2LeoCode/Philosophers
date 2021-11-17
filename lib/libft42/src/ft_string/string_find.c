/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:33:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 17:51:37 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

char	*string_find(const t_string *s, const char *sequence)
{
	const size_t	seq_len = ft_strlen(sequence);
	const char		*ptr = s->begin - 1;

	if (!*sequence)
		return (s->begin);
	while (++ptr <= s->end - seq_len)
		if (*ptr == *sequence && !ft_memcmp(ptr, sequence, seq_len))
			return ((char *)ptr);
	return (NULL);
}
