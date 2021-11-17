/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:36:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 18:44:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

t_string	*string_dup(const t_string *s)
{
	t_string	*ptr;

	ptr = ft_malloc(sizeof(t_string) + sizeof(char) * (s->capacity + 1));
	if (ptr)
	{
		ptr->length = s->length;
		ptr->capacity = s->capacity;
		ptr->begin = ptr->data;
		ptr->end = ptr->data + ptr->length;
		ft_memcpy(ptr->data, s->data, s->capacity + 1);
	}
	return (ptr);
}
