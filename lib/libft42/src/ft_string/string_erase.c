/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_erase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:52:43 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 03:08:39 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <stringft.h>
#include <libft.h>

void	string_erase(t_string *s, unsigned int index, unsigned int n)
{
	if ((size_t)index < s->length && (size_t)(index + n) <= s->length)
	{
		ft_memmove(s->data + index, s->data + index + n,
			s->length - index - n);
		s->length -= n;
		ft_bzero(s->data + s->length, n);
		s->begin = s->data;
		s->end = s->data + s->length;
	}
}
