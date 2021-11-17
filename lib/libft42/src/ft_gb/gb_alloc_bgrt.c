/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_alloc_bgrt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:57:50 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 15:58:22 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <libft.h>
#include <libft_types.h>

short	gb_alloc_bgrt(t_bgrt **addr, t_bgrt data)
{
	*addr = make_bgrt(data.b, data.g, data.r, data.t);
	if (!*addr)
	{
		gb_clear();
		return (GB_FAILURE);
	}
	return (gb_push(*addr, ft_free));
}
