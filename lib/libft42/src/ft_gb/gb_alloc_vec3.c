/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_alloc_vec3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:50:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 15:54:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <libft.h>
#include <libft_types.h>

short	gb_alloc_vec3(t_vec3 **addr, long x, long y, long z)
{
	*addr = make_vec3(x, y, z);
	if (!*addr)
	{
		gb_clear();
		return (GB_FAILURE);
	}
	return (gb_push(*addr, ft_free));
}
