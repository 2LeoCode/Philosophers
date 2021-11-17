/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:33:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 21:37:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <libft.h>

short	gb_alloc(void *addr, size_t size)
{
	void	**ptr;

	ptr = addr;
	*ptr = ft_malloc(size);
	if (!*ptr)
	{
		gb_clear();
		return (GB_FAILURE);
	}
	return (gb_push(*ptr, ft_free));
}
