/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_assign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:20:08 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 18:42:22 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <stringft.h>
#include <libft.h>

short	string_assign(t_string **s, const char *src)
{
	const size_t	src_len = ft_strlen(src);

	if (src_len > (*s)->capacity
		&& string_realloc(s, src_len) == STRING_FAILURE)
		return (STRING_FAILURE);
	ft_memcpy((*s)->data, src, src_len + 1);
	if ((*s)->length > src_len)
		ft_bzero((*s)->data + src_len + 1, (*s)->length - src_len - 1);
	(*s)->length = src_len;
	(*s)->begin = (*s)->data;
	(*s)->end = (*s)->data + (*s)->length;
	return (STRING_SUCCESS);
}
