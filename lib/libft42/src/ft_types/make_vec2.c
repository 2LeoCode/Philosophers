/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_vec2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:30:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 13:32:30 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_types.h>
#include <libft.h>

t_vec2	*make_vec2(long x, long y)
{
	t_vec2	*ptr;

	ptr = ft_malloc(sizeof(t_vec2));
	if (ptr)
	{
		ptr->x = x;
		ptr->y = y;
	}
	return (ptr);
}
