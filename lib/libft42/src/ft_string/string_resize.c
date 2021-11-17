/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:07:46 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 16:29:00 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <stringft.h>
#include <libft.h>

short	string_resize(t_string **s, size_t len, char c)
{
	if (!*s)
	{
		*s = string_new(len);
		if (!*s)
			return (STRING_FAILURE);
		ft_memset((*s)->data, c, len);
	}
	else if (len < (*s)->length)
		ft_bzero((*s)->data + len, (*s)->length - len);
	else
	{
		if (len > (*s)->capacity)
		{
			*s = ft_realloc(*s, sizeof(t_string) + sizeof(char) * (len + 1));
			if (!*s)
				return (STRING_FAILURE);
			(*s)->capacity = len;
		}
		ft_memset((*s)->data + (*s)->length, c, len - (*s)->length);
		(*s)->data[len] = 0;
	}
	(*s)->length = len;
	(*s)->begin = (*s)->data;
	(*s)->end = (*s)->data + len;
	return (STRING_SUCCESS);
}
