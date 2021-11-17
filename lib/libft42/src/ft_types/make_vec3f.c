/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_vec3f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:34:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 13:35:06 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_types.h>
#include <libft.h>

t_vec3f	*make_vec3f(double x, double y, double z)
{
	t_vec3f	*ptr;

	ptr = ft_malloc(sizeof(t_vec3f));
	if (ptr)
	{
		ptr->x = x;
		ptr->y = y;
		ptr->z = z;
	}
	return (ptr);
}
