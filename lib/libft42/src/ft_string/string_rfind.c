/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_rfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:55:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 17:53:41 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

char	*string_rfind(const t_string *s, const char *sequence)
{
	const size_t	seq_len = ft_strlen(sequence);
	const char		*ptr = s->end - seq_len + 1;

	while (--ptr >= s->begin)
		if (*ptr == *sequence && !ft_memcmp(ptr - seq_len, sequence, seq_len))
			return ((char *)ptr);
	return (NULL);
}
