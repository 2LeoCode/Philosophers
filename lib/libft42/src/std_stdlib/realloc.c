/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:31:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/28 22:03:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_int.h>
#include <libft.h>
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	t_block	*old_block;
	t_block	*new_block;
	void	*ret;

	ret = NULL;
	old_block = ptr - sizeof(t_block);
	new_block = malloc(sizeof(t_block) + size);
	if (new_block)
	{
		new_block->size = size;
		if (size > old_block->size)
			size = old_block->size;
		ft_memcpy(new_block->data, old_block->data, size);
		ret = new_block->data;
	}
	free(old_block);
	return (ret);
}
