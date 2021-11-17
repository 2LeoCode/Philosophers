/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:44:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 21:36:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*c_src;
	char		*c_dst;

	if (dst < src)
		return (ft_memcpy(dst, src, n));
	c_src = src;
	c_dst = dst;
	while (n--)
		c_dst[n] = c_src[n];
	return (dst);
}
