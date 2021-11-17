/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_from.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:29:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 18:46:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

t_string	*string_from(const char *s)
{
	const size_t	len = ft_strlen(s);
	t_string		*ptr;

	ptr = ft_malloc(sizeof(t_string) + sizeof(char) * (len + 1));
	if (ptr)
	{
		ptr->length = len;
		ptr->capacity = len;
		ptr->begin = ptr->data;
		ptr->end = ptr->data + len;
		ft_memcpy(ptr->data, s, len + 1);
	}
	return (ptr);
}
