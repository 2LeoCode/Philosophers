/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:55:24 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 18:50:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdint.h>

#ifndef SWAP_BUFSIZE
# define SWAP_BUFSIZE 32
#endif

void	ft_swap(void *a, void *b, size_t size)
{
	uint8_t	buf[SWAP_BUFSIZE];
	size_t	final_size;

	while (size)
	{
		if (size > SWAP_BUFSIZE)
			final_size = SWAP_BUFSIZE;
		else
			final_size = size;
		ft_memcpy(buf, b, final_size);
		ft_memcpy(b, a, final_size);
		ft_memcpy(a, buf, final_size);
		size -= final_size;
	}
}
