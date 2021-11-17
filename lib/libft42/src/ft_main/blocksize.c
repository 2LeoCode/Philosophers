/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocksize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:02:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/13 11:06:54 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_int.h>

size_t	ft_blocksize(const void *m)
{
	const t_block	*block = m - sizeof(t_block);

	return (block->size);
}
