/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_subst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:22:40 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:26:58 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <stringft.h>
#include <libft.h>

t_string	*string_subst(const t_string *s, size_t start, size_t len)
{
	t_string	*ptr;

	ptr = string_new(len);
	if (ptr)
	{
		ft_memcpy(ptr->data, s->data + start, len);
		ptr->length = len;
		ptr->begin = ptr->data;
		ptr->end = ptr->data + len;
	}
	return (ptr);
}
