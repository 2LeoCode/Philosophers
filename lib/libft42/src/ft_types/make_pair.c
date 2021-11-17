/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 13:31:21 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_types.h>
#include <libft.h>

t_pair	*make_pair(void *first, void *second)
{
	t_pair	*ptr;

	ptr = ft_malloc(sizeof(t_pair));
	if (ptr)
	{
		ptr->first = first;
		ptr->second = second;
	}
	return (ptr);
}
