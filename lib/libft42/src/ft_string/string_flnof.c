/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_flnof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:20:53 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 18:15:03 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

char	*string_flnof(const t_string *s, const char *charset)
{
	const size_t	cst_len = ft_strlen(charset);
	const char		*ptr = s->end;

	if (!*charset)
		return (NULL);
	while (--ptr >= s->begin)
		if (!ft_memchr(charset, *ptr, cst_len))
			return ((char *)ptr);
	return (NULL);
}
