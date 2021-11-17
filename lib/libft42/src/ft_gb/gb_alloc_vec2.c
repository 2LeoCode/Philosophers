/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_alloc_vec2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:49:06 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 15:54:24 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <libft.h>
#include <libft_types.h>

short	gb_alloc_vec2(t_vec2 **addr, long x, long y)
{
	*addr = make_vec2(x, y);
	if (!*addr)
	{
		gb_clear();
		return (GB_FAILURE);
	}
	return (gb_push(*addr, ft_free));
}
