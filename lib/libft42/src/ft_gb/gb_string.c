/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:48:35 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/09 16:02:13 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <stringft.h>
#include <libft.h>

static void	gb_destroy_string(t_string **s)
{
	ft_free(*s);
}

t_string	*gb_string_dup(const t_string *s)
{
	t_string	*ptr;

	ptr = string_dup(s);
	if (!ptr)
	{
		gb_clear();
		return (NULL);
	}
	if (gb_push(&ptr, gb_destroy_string) == GB_FAILURE)
		return (NULL);
	return (ptr);
}

t_string	*gb_string_from(const char *s)
{
	t_string	*ptr;

	ptr = string_from(s);
	if (!ptr)
	{
		gb_clear();
		return (NULL);
	}
	if (gb_push(&ptr, gb_destroy_string) == GB_FAILURE)
		return (NULL);
	return (ptr);
}

t_string	*gb_string_new(size_t cap)
{
	t_string	*ptr;

	ptr = string_new(cap);
	if (!ptr)
	{
		gb_clear();
		return (NULL);
	}
	if (gb_push(&ptr, gb_destroy_string) == GB_FAILURE)
		return (NULL);
	return (ptr);
}
