/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_alloc_vec3f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:51:17 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 15:55:21 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gbft_int.h>
#include <libft.h>
#include <libft_types.h>

short	gb_alloc_vec3f(t_vec3f **addr, double x, double y, double z)
{
	*addr = make_vec3f(x, y, z);
	if (!*addr)
	{
		gb_clear();
		return (GB_FAILURE);
	}
	return (gb_push(*addr, ft_free));
}
