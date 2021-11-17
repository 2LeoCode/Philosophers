/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:21:46 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/26 00:37:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_int.h>

#include <stdlib.h>

void	*ft_malloc(size_t size)
{
	t_block	*ptr;

	ptr = malloc(sizeof(t_block) + size);
	if (ptr)
		ptr->size = size;
	return (ptr->data);
}
