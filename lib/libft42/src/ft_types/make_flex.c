/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:36:09 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 17:18:26 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_types.h>
#include <libft.h>

t_flex	*make_flex(size_t size)
{
	t_flex	*ptr;

	ptr = ft_malloc(sizeof(t_flex) + size);
	if (ptr)
		ptr->size = size;
	return (ptr);
}
