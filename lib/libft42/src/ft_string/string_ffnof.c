/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_ffnof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:19:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 17:45:45 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

char	*string_ffnof(const t_string *s, const char *charset)
{
	const size_t	cst_len = ft_strlen(charset);
	const char		*ptr = s->begin - 1;

	if (!*charset)
		return (NULL);
	while (++ptr != s->end)
		if (!ft_memchr(charset, *ptr, cst_len))
			return ((char *)ptr);
	return (NULL);
}
