/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_ffof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:01:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 18:05:16 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

char	*string_ffof(const t_string *s, const char *charset)
{
	const size_t	cst_len = ft_strlen(charset);
	const char		*ptr = s->begin - 1;

	if (!*charset)
		return (s->begin);
	while (++ptr != s->end)
		if (ft_memchr(charset, *ptr, cst_len))
			return ((char *)ptr);
	return (NULL);
}
