/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stpcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:14:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/21 19:31:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_stpcpy(char *dst, const char *src)
{
	size_t	i;

	i = ~0UL;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst + i);
}
