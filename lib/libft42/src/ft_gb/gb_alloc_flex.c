/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_alloc_flex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:00:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:38:09 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <libft.h>
#include <libft_types.h>

short	gb_alloc_flex(t_flex **addr, size_t size)
{
	*addr = make_flex(size);
	if (!*addr)
	{
		gb_clear();
		return (GB_FAILURE);
	}
	return (gb_push(*addr, ft_free));
}
