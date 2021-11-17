/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_vec2f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:32:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 13:33:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_types.h>
#include <libft.h>

t_vec2f	*make_vec2f(double x, double y)
{
	t_vec2f	*ptr;

	ptr = ft_malloc(sizeof(t_vec2f));
	if (ptr)
	{
		ptr->x = x;
		ptr->y = y;
	}
	return (ptr);
}
