/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_app.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:51:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/14 15:12:38 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <stringft.h>
#include <libft.h>

short	string_app(t_string **s, const char *src)
{
	const size_t	src_len = ft_strlen(src);
	const size_t	new_len = src_len + (*s)->length;

	if (new_len > (*s)->capacity
		&& string_realloc(s, new_len) == STRING_FAILURE)
		return (STRING_FAILURE);
	ft_memcpy((*s)->data + (*s)->length, src, src_len + 1);
	(*s)->length = new_len;
	(*s)->begin = (*s)->data;
	(*s)->end = (*s)->data + (*s)->length;
	return (STRING_SUCCESS);
}
