/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stpncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:16:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/21 19:35:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_stpncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = ~0UL;
	while (++i < n && src[i])
		dst[i] = src[i];
	j = i;
	while (i < n)
		dst[i++] = 0;
	return (dst + j);
}
