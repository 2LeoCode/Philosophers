/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 17:36:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringft_int.h>
#include <libft.h>

t_string	*string_new(size_t cap)
{
	t_string	*ptr;

	ptr = ft_malloc(sizeof(t_string) + sizeof(char) * (cap + 1));
	if (ptr)
	{
		ptr->length = 0;
		ptr->capacity = cap;
		ptr->begin = ptr->data;
		ptr->end = ptr->data + 1;
		ft_bzero(ptr->data, cap + 1);
	}
	return (ptr);
}
