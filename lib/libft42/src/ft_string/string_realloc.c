/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:25:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 22:32:18 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <stringft.h>
#include <libft.h>

short	string_realloc(t_string **s, size_t cap)
{
	size_t	zeropad;

	zeropad = 0;
	if (!*s)
		return (STRING_FAILURE);
	if (cap < (*s)->length)
		cap = (*s)->length;
	zeropad = (cap > (*s)->capacity) * (cap - (*s)->capacity);
	if (cap != (*s)->capacity)
	{
		*s = ft_realloc(*s, sizeof(t_string) + sizeof(char) * (cap + 1));
		if (!*s)
			return (STRING_FAILURE);
	}
	ft_bzero((*s)->data + (*s)->capacity + 1, zeropad);
	(*s)->capacity = cap;
	return (STRING_SUCCESS);
}
