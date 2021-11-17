/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:39:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 18:47:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <stringft.h>
#include <libft.h>

short	string_insert(t_string **s, const char *src, unsigned int index)
{
	const size_t	src_len = ft_strlen(src);
	const size_t	new_len = (*s)->length + src_len;

	if (new_len > (*s)->capacity
	&& string_realloc(s, new_len) == STRING_FAILURE)
		return (STRING_FAILURE);
	if ((size_t)index > (*s)->length)
		index = (*s)->length;
	ft_memmove((*s)->data + index + src_len, (*s)->data + index,
			(*s)->length - index);
	ft_memcpy((*s)->data + index, src, src_len);
	(*s)->length = new_len;
	(*s)->begin = (*s)->data;
	(*s)->end = (*s)->data + new_len;
	return (STRING_SUCCESS);
}
