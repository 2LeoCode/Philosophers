/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmemset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:13:05 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/19 18:36:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_cmemset(void *dst, const void *src, size_t src_size, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		ft_memcpy(dst + i, src, src_size);
		i += src_size;
	}
	return (dst);
}