/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmemset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:13:05 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/17 02:59:34 by crochu           ###   ########.fr       */
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
