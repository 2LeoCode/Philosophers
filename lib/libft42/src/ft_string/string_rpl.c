/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_rpl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:17:06 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:08:55 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <stringft.h>
#include <libft.h>

short	string_rpl(t_string **s, const char *src, unsigned int index,
			unsigned int n)
{
	const size_t	src_len = ft_strlen(src);
	size_t			new_len;

	if (index > (*s)->length)
		index = (*s)->length;
	if ((size_t)(index + n) > (*s)->length)
		n = (*s)->length - index;
	new_len = (*s)->length - n + src_len;
	if (new_len > (*s)->capacity
		&& string_realloc(s, new_len) == STRING_FAILURE)
		return (STRING_FAILURE);
	ft_memmove((*s)->data + index + src_len, (*s)->data + index + n,
		(*s)->length - index - n);
	ft_memcpy((*s)->data + index, src, src_len);
	(*s)->length = new_len;
	if (n > src_len)
		ft_bzero((*s)->data + (*s)->length, n - src_len);
	(*s)->begin = (*s)->data;
	(*s)->end = (*s)->data + new_len;
	return (STRING_SUCCESS);
}
