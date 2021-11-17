/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_construct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:39:30 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 21:37:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <libft.h>

static void	*alloc(t_allocf *alloc_fun, void *alloc_param)
{
	if (alloc_param)
		return (alloc_fun(alloc_param));
	return (alloc_fun());
}

short	gb_construct(void *addr, t_allocf *alloc_fun, void *alloc_param,
			t_freef *free_fun)
{
	void	**ptr;

	ptr = addr;
	*ptr = alloc(alloc_fun, alloc_param);
	if (!*ptr)
	{
		gb_clear();
		return (GB_FAILURE);
	}
	return (gb_push(*ptr, free_fun));
}
