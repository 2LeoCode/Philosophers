/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_vec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:33:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 13:34:10 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_types.h>
#include <libft.h>

t_vec3	*make_vec3(long x, long y, long z)
{
	t_vec3	*ptr;

	ptr = ft_malloc(sizeof(t_vec3));
	if (ptr)
	{
		ptr->x = x;
		ptr->y = y;
		ptr->z = z;
	}
	return (ptr);
}
