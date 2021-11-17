/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:43:27 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/28 22:03:08 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_int.h>
#include <libft.h>
#include <stdlib.h>

void	*ft_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	const size_t	total_size = nmemb * size;
	t_block			*old_block;
	t_block			*new_block;

	old_block = ptr - sizeof(t_block);
	new_block = malloc(sizeof(t_block) + total_size);
	if (!new_block)
		return (NULL);
	if (size > old_block->size)
		size = old_block->size;
	ft_memcpy(new_block->data, old_block->data, size);
	free(old_block);
	return (new_block->data);
}
